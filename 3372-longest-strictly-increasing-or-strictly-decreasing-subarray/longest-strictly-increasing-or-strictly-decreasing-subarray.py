class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        lgsa = 1
        smsa = 1
        lgmx = 1
        for i in range(1, len(nums)):
            if nums[i-1] < nums[i]:
                lgsa += 1
                lgmx = max(lgmx, lgsa)
            else:
                lgsa = 1

            if nums[i-1] > nums[i]:
                smsa += 1
                lgmx = max(smsa, lgmx)
            else:
                smsa = 1

        return lgmx