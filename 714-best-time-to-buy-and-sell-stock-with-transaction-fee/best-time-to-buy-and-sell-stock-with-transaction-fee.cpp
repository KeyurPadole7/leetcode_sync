/*class Solution {//memoization
public:
    int f(int idx, int buy, int fee, vector<int>& prices, vector<vector<int>> &dp){
        if(idx == prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = f(idx+1, buy, fee, prices, dp);
        if(buy == 1) profit = max(profit, -prices[idx]-fee+f(idx+1, 0, fee, prices, dp));
        else profit = max(profit, prices[idx]+f(idx+1, 1, fee, prices, dp));

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, fee, prices, dp);
    }
};*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int idx=n-1; idx>=0; idx--){
            dp[idx][1] = max(dp[idx+1][1], -prices[idx]-fee+dp[idx+1][0]);
            dp[idx][0] = max(dp[idx+1][0], prices[idx]+dp[idx+1][1]);
        }

        return dp[0][1];
    }
};