#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int p = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (p >= 0 && nums[p] >= nums[p + 1]) {
            p--;
        }

        // Step 2: If a valid pivot was found, swap with the smallest larger element on the right
        if (p >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[p]) {
                j--;
            }
            std::swap(nums[p], nums[j]);
        }

        // Step 3: Reverse the sequence from p + 1 to the end
        std::reverse(nums.begin() + p + 1, nums.end());
    }
};