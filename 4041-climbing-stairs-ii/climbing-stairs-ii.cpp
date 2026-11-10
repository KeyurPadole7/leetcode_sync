class Solution {
public:
    int f(int idx, vector<int>& costs, vector<int> &dp){
        if(idx<1) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int mincost = min(f(idx-1, costs, dp) + 1, min(f(idx-2, costs, dp) + 4, f(idx-3, costs, dp) + 9));
        return dp[idx] = mincost + costs[idx-1];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return f(n, costs, dp);
    }
};