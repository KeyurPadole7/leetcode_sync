/*class Solution { //Memoized
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mx = -1e9;
        for(int idx=i; idx<=j; idx++){
            int cost = nums[i-1]*nums[idx]*nums[j+1];
            cost += f(i, idx-1, nums, dp) + f(idx+1, j, nums, dp);
            mx = max(mx, cost);
        }
        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(1, n-2, nums, dp);
    }
};*/

class Solution { 
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=n-2; i>=1; i--){
            for(int j=i; j<=n-2; j++){
                int mx = -1e9;
                for(int idx=i; idx<=j; idx++){
                    int cost = nums[i-1]*nums[idx]*nums[j+1];
                    cost += dp[i][idx-1] + dp[idx+1][j];
                    mx = max(mx, cost);
                }
                dp[i][j] = mx;
            }
        }

        return dp[1][n-2];
    }
};