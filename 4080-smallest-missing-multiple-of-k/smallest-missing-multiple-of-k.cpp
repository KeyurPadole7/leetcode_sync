class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> u;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]%k == 0) u.insert(nums[i]/k);
        }

        for(int i=1; i<=nums.size()+1; i++){
            if(!u.contains(i)) return k*i;
        }

        return (nums.size()+1)*k;
    }
};