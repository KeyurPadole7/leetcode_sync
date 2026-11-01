class Solution:
    def minMoves(self, nums: list[int]) -> int:
        mn = min(nums)
        count = 0
        for i in nums:
            count += i - mn

        return count