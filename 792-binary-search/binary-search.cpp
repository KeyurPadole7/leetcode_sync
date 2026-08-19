class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l=0, h=nums.size()-1;
        return helper(nums, tar, l, h);
    }

    int helper(vector<int>& nums, int tar, int l, int h){
        if(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid] == tar) return mid;
            else if(tar < nums[mid]) return helper(nums, tar, l, mid-1);
            else return helper(nums, tar, mid+1, h);
        }
        return -1;
    }
};