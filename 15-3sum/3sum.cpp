#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        
        // 1. Sort the input
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Early exit: smallest value > 0 means sum can never be 0
            if (nums[i] > 0) break;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    // Skip duplicates for second and third elements inline
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                } else if (sum < 0) {
                    l++; // Need a larger sum
                } else {
                    r--; // Need a smaller sum
                }
            }
        }

        return ans;
    }
};