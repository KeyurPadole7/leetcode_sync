class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof=0;
        int minbuy = prices[0];
        for(int i = 1; i<prices.size(); i++){
            maxprof = max(prices[i]-minbuy,maxprof);
            minbuy = min(minbuy, prices[i]);
        }
        return maxprof;
    }
};