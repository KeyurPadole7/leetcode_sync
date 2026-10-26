class Solution:
    def islandPerimeter(self, grid: list[list[int]]) -> int:
        
        n, m = len(grid), len(grid[0])
        vis = [[False]*m for _ in range(n)]

        def dfs(r, c, prev):
            if r<0 or c<0 or r>=n or c>=m or grid[r][c]==0:
                return 1

            vis[r][c] = True
            sm = 0
            if r+1==n or not vis[r+1][c]:
                sm += dfs(r+1, c, (r,c))
            if r==0 or not vis[r-1][c]:
                sm += dfs(r-1, c, (r,c))
            if c+1==m or not vis[r][c+1]:
                sm += dfs(r, c+1, (r,c))
            if c==0 or not vis[r][c-1]:
                sm += dfs(r, c-1, (r,c))

            return sm
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return dfs(i, j, (-1,-1))
            