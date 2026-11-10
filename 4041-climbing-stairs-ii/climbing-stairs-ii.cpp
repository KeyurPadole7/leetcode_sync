/* Memoization
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
};*/


class Solution { // Tabulation
public:
    int climbStairs(int n, vector<int>& cost) {
        if(n==1) return cost[0]+1;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1 + cost[1-1];
        dp[2] = cost[2-1] + min(1+dp[1], 4+dp[0]);

        for(int i=3; i<=n; i++){
            dp[i] = cost[i-1] + min(dp[i-1]+1, min(dp[i-2]+4, dp[i-3]+9));
        }

        return dp[n];
    }
};