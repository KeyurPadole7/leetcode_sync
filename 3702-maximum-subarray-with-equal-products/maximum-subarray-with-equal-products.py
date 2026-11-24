import math
class Solution:
    def maxLength(self, nums: List[int]) -> int:
        mx = 0
        n = len(nums)
        for i in range(n):
            product = 1
            g, l = 0, 1

            for j in range(i, n):
                product *= nums[j]
                g = math.gcd(g, nums[j])
                l = math.lcm(l, nums[j])

                if product == g * l:
                    mx = max(mx, j-i+1)

        return mx

