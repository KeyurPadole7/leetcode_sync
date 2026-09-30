class Solution { //Memoization
public:
    int f(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(idx == prices.size() || cap==0) return 0;

        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int profit;
        if(buy == 1){
            profit = max(-prices[idx]+f(idx+1, 0, cap, prices, dp), f(idx+1, 1, cap, prices, dp));
        }else{
            profit = max(prices[idx]+f(idx+1, 1, cap-1, prices, dp), f(idx+1, 0, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, prices, dp);
    }
};

// class Solution { //Tabulation
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
//         return f(0, 1, k, prices, dp);
//     }
// };