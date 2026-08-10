class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int val : nums){
            if(s.contains(val)) return val;
            else s.insert(val);
        }

        return -1;
    }
};