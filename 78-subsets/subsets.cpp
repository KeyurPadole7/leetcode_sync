class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> bkt;

        fss(nums, bkt, 0);
        return ans;
    }

    void fss(vector<int>& nums, vector<int>& bkt, int i){
        if(i == nums.size()){
            ans.push_back({bkt});
            return;
        }

        fss(nums, bkt, i+1);

        bkt.push_back(nums[i]);
        fss(nums, bkt, i+1);

        bkt.pop_back();
        
    }
};