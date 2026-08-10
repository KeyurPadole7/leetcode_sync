class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> pfs(n,0);

        pfs[0] = nums[0];

        for(int i = 1; i<n; i++){
            pfs[i] = pfs[i-1] + nums[i];
        }

        unordered_map<int,int> m;

        for(int j=0; j<n; j++){
            if(pfs[j] == k) count++;

            int val = pfs[j] - k;

            if(m.contains(val)){
                count += m[val];
            }

            m[pfs[j]]++;
        }

        return count;
    }
};