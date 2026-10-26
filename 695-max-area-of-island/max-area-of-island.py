class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        
        n, m = len(grid), len(grid[0])
        
        def dfs(r,c):
            if r<0 or c<0 or r>=n or c>=m or grid[r][c] == 0:
                return 0
            
            grid[r][c] = 0
            sm = 1
            sm += dfs(r+1,c)
            sm += dfs(r-1,c)
            sm += dfs(r,c+1)
            sm += dfs(r,c-1)

            return sm

        mxar = 0
        for i in range(n):
            for j in range(m):
                if(grid[i][j]==1):
                    mxar = max(mxar, dfs(i,j))

        return mxar