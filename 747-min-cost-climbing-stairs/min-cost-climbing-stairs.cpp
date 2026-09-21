class Solution {
public:
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();

    //     if(n==2) return min(cost[0], cost[1]);

    //     vector<int> dp(n+1);
    //     dp[0] = 0;
    //     dp[1] = 0;

    //     for(int i=2; i<=n; i++){
    //         dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
    //     }

    //     return dp[n];
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n==2) return min(cost[0], cost[1]);

        vector<int> dp(n+1);
        int prev2 = 0;
        int prev1 = 0;
        int res;

        for(int i=2; i<=n; i++){
            res = min(prev1+cost[i-1], prev2+cost[i-2]);
            prev2 = prev1;
            prev1 = res;
        }

        return res;
    }
};