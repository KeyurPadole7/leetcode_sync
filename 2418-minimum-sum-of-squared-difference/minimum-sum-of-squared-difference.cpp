class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> count(100005, 0);
        long long totdiff = 0;

        int maxd=0;
        for(int i=0; i<n; i++){
            int d = abs(nums1[i]-nums2[i]);
            count[d]++;
            totdiff += d;
            maxd = max(maxd, d);
        }

        long long k = 1LL*k1 + k2;

        if(k>=totdiff) return 0;

        for(int d=maxd; d>=1; d--){
            if(count[d]==0) continue;
            
            if(count[d]<=k){
                count[d-1]+= count[d];
                k-= count[d];
                count[d] = 0;
            }else{
                count[d-1] += k;
                count[d] -= k;
                k = 0;
                break;
            }
        }

        long long result = 0;

        for(int i=maxd; i>=0; i--){
            if(count[i]>0){
                result += 1LL*count[i]*i*i;
            }
        }
        
        return result;
    }
};