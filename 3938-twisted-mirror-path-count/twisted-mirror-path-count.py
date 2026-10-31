class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7

        n = len(grid)
        m = len(grid[0])

        dp = [[0] * m for _ in range(n)]
        dp[0][0] = 1

        def move(i, j, direction):
            if direction == 0:  # Right
                j += 1
            else:               # Down
                i += 1

            while i < n and j < m and grid[i][j] == 1:

                if direction == 0:
                    i += 1
                    direction = 1
                else:
                    j += 1
                    direction = 0

            if i < n and j < m:
                dp[i][j] = (dp[i][j] + dp[x][y]) % MOD

        for x in range(n):
            for y in range(m):

                if dp[x][y] == 0:
                    continue

                if x == n - 1 and y == m - 1:
                    continue

                move(x, y, 0)  # Right
                move(x, y, 1)  # Down

        return dp[n - 1][m - 1]