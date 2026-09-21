class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);
        vector<long long> result(k, 0);

        for(int num: nums){
            vector<long long> dp_next(k, 0);
            int val = num % k;

            dp_next[val]++;

            for(int rem=0; rem<k; rem++){
                if(dp[rem] > 0){
                    int new_rem = (1LL * rem * val) % k;
                    dp_next[new_rem] += dp[rem];
                }
            }

            for(int rem=0; rem<k; rem++){
                result[rem] += dp_next[rem];
            }

            dp = move(dp_next);
        }

        return result;


    }
};