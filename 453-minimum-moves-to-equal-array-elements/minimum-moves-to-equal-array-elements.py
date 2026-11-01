class Solution:
    def minMoves(self, nums: list[int]) -> int:
        return sum(nums) - min(nums) * len(nums)
        # mn = min(nums)
        # count = 0
        # for i in nums:
        #     count += i - mn

        # return count
