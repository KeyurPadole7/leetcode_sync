class Solution {
public:
    // int helper(vector<int>& nums, int i, int j, int x, int count, map<pair<pair<int,int>,int>, int>& dp){
    //     if(x == 0) return count;
    //     if(i>j) return INT_MAX;
        
    //     if(dp.contains({{i,j}, x})) return dp[{{i,j}, x}];
    //     int l = helper(nums, i+1, j, x-nums[i], count+1, dp);
    //     int r = helper(nums, i, j-1, x-nums[j], count+1, dp);

    //     return dp[{{i,j}, x}] = min(l,r);
    // }

    // int minOperations(vector<int>& nums, int x) {
    //     int n = nums.size();
    //     map<pair<pair<int,int>,int>, int> dp; 

    //     int count = helper(nums, 0, nums.size()-1, x, 0, dp);
    //     return INT_MAX == count ? -1 : count;
    // }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long target = accumulate(nums.begin(), nums.end(), 0LL) - x;

        if(target<0) return -1;
        long long currsum = 0;
        int left = 0;
        int sz = -1;


        for(int right=0; right<n; right++){
            currsum += nums[right];

            while (currsum > target && left <= right){
                currsum -= nums[left++];
            }

            if(currsum == target) sz = max(sz, right-left+1);
        }

        return sz == -1 ? -1 : n-sz;
    }
};