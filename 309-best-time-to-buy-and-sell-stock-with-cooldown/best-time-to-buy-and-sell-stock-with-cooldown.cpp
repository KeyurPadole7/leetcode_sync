/*class Solution { //Memoization
public:
    int f(int idx, int buy, vector<int>& prices, vector<vector<int>> dp){
        if(idx == prices.size()+1) return 0;
        if(idx == prices.size()) return 0;
    
        if(dp[idx][buy]!=-1) return dp[idx][buy];

        int profit = f(idx+1, buy, prices, dp);
        if(buy == 1) profit = max(profit, -prices[idx] + f(idx+1, 0, prices, dp));
        else profit = max(profit, prices[idx] + f(idx+2, 1, prices, dp));
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0,1,prices,dp);
    }
};*/

class Solution { //Tabulation
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int profit = dp[idx+1][buy];
                if(buy == 1) profit = max(profit, -prices[idx] + dp[idx+1][0]);
                else profit = max(profit, prices[idx] + dp[idx+2][1]);
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};