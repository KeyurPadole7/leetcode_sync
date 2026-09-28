/*class Solution { //Memoization
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
};*/

/*class Solution { //Tabulation
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        dp[n-1][0] = prices[n-1];
        dp[n-1][1] = 0;
        for(int i=n-2; i>=0; i--){
            dp[i][1] = max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);
            dp[i][0] = max(prices[i]+dp[i+1][1], 0+dp[i+1][0]);
        }

        return dp[0][1];
    }
};*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for(int i=n-1; i>=0; i--){
            curr[1] = max(-prices[i]+ahead[0], 0+ahead[1]);
            curr[0] = max(prices[i]+ahead[1], 0+ahead[0]);
            ahead = curr;
        }

        return ahead[1];
    }
};