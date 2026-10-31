class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7

        n = len(grid)
        m = len(grid[0])

        ddp = [[0] * m for _ in range(n)]
        rdp = [[0] * m for _ in range(n)]

        # Starting position
        rdp[0][0] = 1

        for i in range(n):
            for j in range(m):

                if i == 0 and j == 0:
                    continue

                # Arriving from the left
                if j > 0:
                    if grid[i][j-1] == 0:
                        rdp[i][j] = (
                            rdp[i][j-1] + ddp[i][j-1]
                        ) % MOD
                    else:
                        rdp[i][j] = ddp[i][j-1]

                # Arriving from above
                if i > 0:
                    if grid[i-1][j] == 0:
                        ddp[i][j] = (
                            rdp[i-1][j] + ddp[i-1][j]
                        ) % MOD
                    else:
                        ddp[i][j] = rdp[i-1][j]

        if grid[n-1][m-1] == 1:
            return 0

        return (ddp[n-1][m-1] + rdp[n-1][m-1]) % MOD