class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i =0; i<nums.size(); i++){
            if(i==nums.size()-1) return nums[i];
            if(nums[i] != nums[i+1]) return nums[i];
            else i++;
        }
        return -1;

    }
};