class Solution:
    def trap(self, heights: list[int]) -> int:
        n = len(heights)
        lmax = [0]*n
        rmax = [0]*n

        lmax[0] = heights[0]
        rmax[-1] = heights[-1]
        trap = 0

        for i in range(1,n):
            lmax[i] = max(lmax[i-1], heights[i])
            rmax[n-i-1] = max(rmax[n-i], heights[n-i-1])

        for i in range(n):
            trap += min(lmax[i], rmax[i]) - heights[i]

        return trap
