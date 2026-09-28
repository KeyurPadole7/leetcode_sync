class Solution {
public:
    int f(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit;
        if(buy == 1) profit = max(-prices[idx]+f(idx+1, 0, prices, dp), 0+f(idx+1, 1, prices, dp));
        else profit = max(prices[idx]+f(idx+1, 1, prices, dp), 0+f(idx+1, 0, prices, dp));

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};