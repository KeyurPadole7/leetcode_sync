class Solution:
    def trap(self, height: list[int]) -> int:
        # n = len(heights)
        # lmax = [0]*n
        # rmax = [0]*n

        # lmax[0] = heights[0]
        # rmax[-1] = heights[-1]
        # trap = 0

        # for i in range(1,n):
        #     lmax[i] = max(lmax[i-1], heights[i])
        #     rmax[n-i-1] = max(rmax[n-i], heights[n-i-1])

        # for i in range(n):
        #     trap += min(lmax[i], rmax[i]) - heights[i]

        # return trap

        n = len(height)
        lmax = height[0]
        rmax = height[-1]
        trap, l, r = 0, 0, n-1

        while(l<=r):
            while l<=r and lmax<rmax:
                trap += lmax - height[l] if lmax > height[l] else 0
                lmax = max(lmax, height[l])
                l += 1
            while l<=r and lmax>=rmax:
                trap += rmax - height[r] if rmax > height[r] else 0
                rmax = max(rmax, height[r])
                r -= 1

        return trap
            