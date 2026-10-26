class Solution:
    def maxArea(self, height: list[int]) -> int:
        l, r = 0, len(height)-1

        mxar = 0
        while l<r:
            mxar = max(mxar, (r-l)*min(height[l], height[r]))
            if(height[l]<height[r]):
                l += 1
            else:
                r -= 1

        return mxar
            