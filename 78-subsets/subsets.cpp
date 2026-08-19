class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> bkt;

        fss(nums, bkt, ans, 0);
        return ans;
    }

    void fss(vector<int>& nums, vector<int>& bkt, vector<vector<int>>& ans, int i){
        if(i == nums.size()){
            ans.push_back({bkt});
            return;
        }

        fss(nums, bkt, ans, i+1);

        bkt.push_back(nums[i]);
        fss(nums, bkt, ans, i+1);

        bkt.pop_back();
        
    }
};