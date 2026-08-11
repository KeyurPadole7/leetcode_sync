class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        
        // Step 1: Calculate the sum of the longest sequential prefix
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // Step 2: Store elements in a hash set for O(1) lookups
        std::unordered_set<int> seen(nums.begin(), nums.end());
        
        // Step 3: Increment sum until it's not present in the set
        while (seen.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};