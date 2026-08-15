class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_sum = 0;
        bool has_non_zero = false;

        for (int val : nums) {
            xor_sum ^= val;
            if (val != 0) {
                has_non_zero = true;
            }
        }

        if (xor_sum != 0) {
            return nums.size();
        }

        // If total XOR is 0, we can drop any non-zero element 
        // to make the remaining XOR sum non-zero.
        return has_non_zero ? (nums.size() - 1) : 0;
    }
};