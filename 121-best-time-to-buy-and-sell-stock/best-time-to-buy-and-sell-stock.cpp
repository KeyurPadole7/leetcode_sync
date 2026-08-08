class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof=0;
        int minbuy = prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]-minbuy>maxprof) maxprof= prices[i]-minbuy;
            if(prices[i]<minbuy) minbuy = prices[i];
        }
        return maxprof;
    }
};