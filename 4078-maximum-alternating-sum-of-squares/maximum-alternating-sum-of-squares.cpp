/*class Solution {
public:
    long long f(int i, int pos, vector<int>& nums, vector<vector<long long>>& dp) {
        int n = nums.size();
        int max_allowed = (n + 1) / 2;
        int neg = (n - 1 - i) - pos;

        if (pos > max_allowed || neg > max_allowed) return -1e17;

        if (i < 0) {
            int t = pos - neg;
            if (t == -1 || t == 0 || t == 1) return 0;
            return -1e17;
        }

        if (dp[i][pos] != -1) return dp[i][pos];

        long long val = 1LL * nums[i] * nums[i];

        long long take_pos = f(i - 1, pos + 1, nums, dp) + val;
        long long take_neg = f(i - 1, pos, nums, dp) - val;

        return dp[i][pos] = max(take_pos, take_neg);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int max_allowed = (n + 1) / 2;
        vector<vector<long long>> dp(n, vector<long long>(max_allowed + 2, -1));
        return f(n - 1, 0, nums, dp);
    }
};*/


/*class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int max_pos = (n + 1) / 2;
        const long long INF = 1e17;

        // dp[pos][neg] represents max alternating sum formed
        vector<vector<long long>> dp(max_pos + 2, vector<long long>(max_pos + 2, -INF));
        dp[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            long long val = 1LL * nums[i] * nums[i];
            vector<vector<long long>> next_dp(max_pos + 2, vector<long long>(max_pos + 2, -INF));

            for (int pos = 0; pos <= min(i, max_pos); ++pos) {
                int neg = i - pos;
                if (neg < 0 || neg > max_pos || dp[pos][neg] == -INF) continue;

                // Pick nums[i] with positive sign
                if (pos + 1 <= max_pos) {
                    next_dp[pos + 1][neg] = max(next_dp[pos + 1][neg], dp[pos][neg] + val);
                }

                // Pick nums[i] with negative sign
                if (neg + 1 <= max_pos) {
                    next_dp[pos][neg + 1] = max(next_dp[pos][neg + 1], dp[pos][neg] - val);
                }
            }
            dp = move(next_dp);
        }

        long long ans = -INF;
        for (int pos = 0; pos <= max_pos; ++pos) {
            int neg = n - pos;
            if (neg >= 0 && neg <= max_pos) {
                int diff = pos - neg;
                if (diff == -1 || diff == 0 || diff == 1) {
                    ans = max(ans, dp[pos][neg]);
                }
            }
        }

        return ans;
    }
};*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums){
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] *= nums[i];
        }

        sort(nums.begin(), nums.end(), greater<int>());

        long long ans = 0;
        for(int i=0; i<n/2; i++){
            ans += nums[i];
            ans -= nums[n-i-1];
        }
        if(n%2!=0) ans += nums[n/2];

        return ans;
    }
};