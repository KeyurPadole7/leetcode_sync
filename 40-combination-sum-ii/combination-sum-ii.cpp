class Solution {
public:
    void f(int idx, int target, vector<int>& nums, vector<int>& ctr, vector<vector<int>>& ans){
        if(target<0) return;
        if(target==0){
            ans.push_back(ctr);
            return;
        }
        
        int n = nums.size();
        if(idx==n) return;

        for(int i=idx; i<n; i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            ctr.push_back(nums[i]);
            f(i+1, target-nums[i], nums, ctr, ans);
            ctr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> ctr;
        
        f(0, target, nums, ctr, ans);
        return ans;
    }
};