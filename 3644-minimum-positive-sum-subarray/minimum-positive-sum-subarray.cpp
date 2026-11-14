class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> presum(n, 0);

        presum[0] = nums[0];

        for(int i = 1; i < n; i++){
            presum[i] = presum[i-1] + nums[i];
        }

        int mn = INT_MAX;

        for(int len = l; len <= r; len++){
            for(int i = len-1; i < n; i++){

                int sum = presum[i];

                if(i-len >= 0){
                    sum -= presum[i-len];
                }

                if(sum > 0){
                    mn = min(mn, sum);
                }
            }
        }

        return mn == INT_MAX ? -1 : mn;
    }
};