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
        vector<int> ahead1(2,0), ahead2(2,0), curr(2,0);

        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int profit = ahead1[buy];
                if(buy == 1) profit = max(profit, -prices[idx] + ahead1[0]);
                else profit = max(profit, prices[idx] + ahead2[1]);
                curr[buy] = profit;
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1[1];
    }
};