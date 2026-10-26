class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dp = copy.deepcopy(grid)

        print(dp)

        for i in range(n):
            for j in range(m):
                if i==0 and j==0:
                    continue
                if(i==0):
                    dp[0][j] += dp[0][j-1]
                elif(j==0):
                    dp[i][0] += dp[i-1][0]
                else:
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1])

        print(dp)

        return dp[n-1][m-1]