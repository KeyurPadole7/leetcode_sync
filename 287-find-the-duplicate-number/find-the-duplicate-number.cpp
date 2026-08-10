class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i = 0; i<=n; i++){
            if(s.contains(nums[i])){
                return nums[i];
            }
            else{
                s.insert(nums[i]);
            }
        }

        return -1;
    }
};