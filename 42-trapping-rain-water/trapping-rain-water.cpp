class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxl = 0, maxr = 0;

        vector<int> lm(n,0);
        vector<int> rm(n,0);

        for(int i = 0; i<n; i++){
            maxl = max(maxl, height[i]);
            lm[i] = maxl;

            maxr = max(maxr, height[n-i-1]);
            rm[n-i-1] = maxr;
        }

        int sum = 0;

        for(int i = 0; i<n; i++){
            sum += min(lm[i],rm[i]) - height[i];
        }
        
        return sum;
    }
};