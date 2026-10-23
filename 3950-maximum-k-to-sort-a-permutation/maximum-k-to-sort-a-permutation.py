class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        k = -1

        for i in range(len(nums)):
            if i!=nums[i]:
                k = nums[i] if k == -1 else (nums[i]&k)
        
        return 0 if k == -1 else k