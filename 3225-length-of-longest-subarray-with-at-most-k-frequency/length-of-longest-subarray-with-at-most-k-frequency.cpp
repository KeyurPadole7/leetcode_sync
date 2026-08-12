class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int r = 0, l = 0;
        int maxl = 0;
        
        int n = nums.size();

        unordered_map<int,int> m;

        while(l<=r && r < n){
            if(m.contains(nums[r]) && m[nums[r]] == k){
                while(nums[l] != nums[r]){
                    m[nums[l]]--;
                    l++;
                } 
                m[nums[l]]--;
                l++;
            }
            m[nums[r]]++;
            maxl = max(maxl,r-l+1);
            r++;
        }
        
        return maxl;
    }
};