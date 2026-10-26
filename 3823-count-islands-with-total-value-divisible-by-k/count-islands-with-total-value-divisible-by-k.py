class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        n = len(grid)
        m = len(grid[0])
        
        def dfs(r,c):
            if(r<0 or c<0 or r>=n or c>=m or grid[r][c]==0):
                return 0
            
            sm = grid[r][c]
            grid[r][c] = 0
            sm += dfs(r+1,c)
            sm += dfs(r-1,c)
            sm += dfs(r,c+1)
            sm += dfs(r,c-1)
            
            return sm
        
        count = 0
        for i in range(n):
            for j in range(m):
                if(grid[i][j] != 0):
                    if(dfs(i,j)%k==0):
                        count += 1
        
        return count


            