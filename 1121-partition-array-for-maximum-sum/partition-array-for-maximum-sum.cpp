class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int mxnum = -1e9;
            int mxsum = -1e9;

            for(int j=i; j<min(n, i+k); j++){
                mxnum = max(mxnum, arr[j]);
                int sum = (j-i+1)*mxnum + dp[j+1];
                mxsum = max(mxsum, sum);
            }

            dp[i] = mxsum;
        }

        return dp[0];
    }
};