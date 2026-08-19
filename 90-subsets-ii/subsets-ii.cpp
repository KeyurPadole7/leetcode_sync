class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> bkt;

        fss(nums, bkt, 0);
        return ans;
    }

    void fss(vector<int>& nums, vector<int>& bkt, int i){
        if(i == nums.size()){
            ans.push_back(bkt);
            return;
        }

        bkt.push_back(nums[i]);
        fss(nums, bkt, i+1);

        bkt.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        fss(nums, bkt, i+1);

        return;
    }
};