class Solution {
public:
    int f(int i, vector<int>& arr, int &k, vector<int>& dp){
        int n = arr.size();
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];
        int mxnum = -1e9;
        int mxsum = -1e9;

        for(int j=i; j<min(n, i+k); j++){
            mxnum = max(mxnum, arr[j]);
            int sum = (j-i+1)*mxnum + f(j+1, arr, k, dp);
            mxsum = max(mxsum, sum);
        }

        return dp[i] = mxsum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);

        return f(0, arr, k, dp);
    }
};