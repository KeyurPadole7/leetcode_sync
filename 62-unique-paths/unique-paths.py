class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = []
        for _ in range(n):
            row = [1]*m
            dp.append(row)

        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[n-1][m-1]