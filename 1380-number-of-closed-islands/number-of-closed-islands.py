class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        
        def dfs(i,j):
            if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==1):
                return
            grid[i][j] = 1

            dfs(i, j+1)
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j-1)

        for i in range(n):
            if(grid[i][0]==0):
                dfs(i,0)
            if(grid[i][m-1]==0):
                dfs(i, m-1)
        
        for j in range(m):
            if(grid[0][j]==0):
                dfs(0,j)
            if(grid[n-1][j]==0):
                dfs(n-1,j)

        count = 0
        for i in range(n):
            for j in range(m):
                if(grid[i][j]==0):
                    dfs(i,j)
                    count += 1

        return count

        return count
            
