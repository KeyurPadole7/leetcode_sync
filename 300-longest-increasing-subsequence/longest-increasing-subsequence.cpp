/*class Solution { //Recurssion
public:
    int f(int idx, int preidx, vector<int>& nums){
        if(idx==nums.size()) return 0;

        int len = f(idx+1, preidx, nums); // Not Take
        if(preidx==-1 || nums[idx]>nums[preidx]) len = max(len, 1+f(idx+1, idx, nums));

        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return f(0, -1, nums);
    }
};*/

class Solution { //Memoization
public:
    int f(int idx, int preidx, vector<int>& nums, vector<vector<int>> &dp){
        if(idx==nums.size()) return 0;

        if(dp[idx][preidx+1] != -1) return dp[idx][preidx+1];

        int len = f(idx+1, preidx, nums, dp); // Not Take
        if(preidx==-1 || nums[idx]>nums[preidx]) len = max(len, 1+f(idx+1, idx, nums, dp)); //Take

        return dp[idx][preidx+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};