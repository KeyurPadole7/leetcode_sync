class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums, 0);
        return ans;
    }

    void per(vector<int>& nums, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            per(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};