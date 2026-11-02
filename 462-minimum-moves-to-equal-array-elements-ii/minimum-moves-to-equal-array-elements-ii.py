class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()

        n = len(nums)
        mid = nums[n//2]
        count = 0
        for i in nums:
            count += abs(mid - i)

        return count