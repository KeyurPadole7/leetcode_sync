/*class Solution { //Memoization
public:
    long long f(int idx, int ntrans, int strans, int k, vector<int>& prices, vector<vector<vector<long long>>> &dp){
        if(ntrans + strans == 2*k) return 0;
        if(idx == prices.size()){
            if(ntrans%2==0 && strans%2==0) return 0;
            else return -1e15;
        }

        if(dp[idx][ntrans][strans]!=-1) return dp[idx][ntrans][strans];

        long long profit = f(idx+1, ntrans, strans, k, prices, dp);
        if(ntrans%2 == 0){
            if(strans%2 == 0){ //buy n, sell s
                profit = max(-prices[idx]+f(idx+1, ntrans+1, strans, k, prices, dp),
                            max(profit, prices[idx]+f(idx+1, ntrans, strans+1, k, prices, dp)));
            }
            else{//both buy
                profit = max(-prices[idx]+f(idx+1, ntrans+1, strans, k, prices, dp),
                            max(profit,-prices[idx]+f(idx+1, ntrans, strans+1, k, prices, dp)));
            }
        }else{
            if(strans%2 == 0){//both sell
                profit = max(prices[idx]+f(idx+1, ntrans+1, strans, k, prices, dp),
                            max(profit, prices[idx]+f(idx+1, ntrans, strans+1, k, prices, dp)));
            }
            else{//sell n, buy s
                profit = max(prices[idx]+f(idx+1, ntrans+1, strans, k, prices, dp),
                            max(profit, -prices[idx]+f(idx+1, ntrans, strans+1, k, prices, dp)));
            }
        }
        return dp[idx][ntrans][strans] = profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long >>> dp(prices.size(), vector<vector<long long>>(2*k+1, vector<long long>(2*k+1, -1)));
        return f(0, 0, 0, k, prices, dp);
    }
};*/


class Solution {
public:
    long long f(int idx, int count, int state, int k, vector<int>& prices, vector<vector<vector<long long>>> &dp){
        if(count == k && state == 0) return 0;
        if(idx == prices.size()){
            return state==0? 0 : -1e15;
        }

        if(dp[idx][count][state]!=-1e15) return dp[idx][count][state];

        long long profit = f(idx+1, count, state, k, prices, dp);
        if(state == 0){
            profit = max(profit, -prices[idx]+f(idx+1, count, 1, k, prices, dp)); //long buy
            profit = max(profit, prices[idx]+f(idx+1, count, 2, k, prices, dp)); //short sell
        }else if(state == 1){
            profit = max(profit, prices[idx]+f(idx+1, count+1, 0, k, prices, dp));//long sell
        }else{
            profit = max(profit, -prices[idx]+f(idx+1, count+1, 0, k, prices, dp));//short buy
        }
        return dp[idx][count][state] = profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long>>> dp(prices.size(), vector<vector<long long>>(k, vector<long long>(3, -1e15)));
        return f(0, 0, 0, k, prices, dp);
    }
};