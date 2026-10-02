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

/*class Solution { //Memoization
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
};*/

/*class Solution { //Tabulation
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int idx=n-1; idx>=0; idx--){
            for(int preidx=idx-1; preidx>=-1; preidx--){
                int len = dp[idx+1][preidx+1]; // Not Take
                if(preidx==-1 || nums[idx]>nums[preidx]) len = max(len, 1+dp[idx+1][idx+1]); //Take
                dp[idx][preidx+1] = len;
            }
        }
        return dp[0][0];
    }
};*/

class Solution { //Space Optamized
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> curr(n+1, 0), ahead(n+1, 0);
        
        for(int idx=n-1; idx>=0; idx--){
            for(int preidx=idx-1; preidx>=-1; preidx--){
                int len = ahead[preidx+1]; // Not Take
                if(preidx==-1 || nums[idx]>nums[preidx]) len = max(len, 1+ahead[idx+1]); //Take
                curr[preidx+1] = len;
            }
            ahead = curr;
        }
        return ahead[0];
    }
};