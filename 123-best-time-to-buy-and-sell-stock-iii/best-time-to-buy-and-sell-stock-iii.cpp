/*class Solution {
public:
    int f(int idx, int buy, int cap, vector<int>& p, vector<vector<vector<int>>> &dp){
        if(cap == 0 || idx == p.size()) return 0;

        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        int profit = 0;
        if(buy==1) profit =  max(-p[idx]+f(idx+1, 0, cap, p, dp), f(idx+1, 1, cap, p, dp));
        else profit = max(p[idx]+f(idx+1, 1, cap-1, p, dp), f(idx+1, 0, cap, p, dp));

        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};*/

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int profit = 0;
                    if(buy==1) profit =  max(-p[idx]+dp[idx+1][0][cap], dp[idx+1][1][cap]);
                    else profit = max(p[idx]+dp[idx+1][1][cap-1], dp[idx+1][0][cap]);

                    dp[idx][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};