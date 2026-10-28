# from functools import cache

# class Solution:
#     def minCost(self, grid: list[list[int]]) -> int:
#         n, m = len(grid), len(grid[0])

#         @cache
#         def f(i: int, j: int, xo: int) -> int:
#             xo ^= grid[i][j]

#             # Reached destination
#             if i == n - 1 and j == m - 1:
#                 return xo

#             res = float('inf')
#             if i + 1 < n:
#                 res = min(res, f(i + 1, j, xo))
#             if j + 1 < m:
#                 res = min(res, f(i, j + 1, xo))

#             return res

#         return f(0, 0, 0)


class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        
        # dp[i][j] stores all distinct reachable XOR sums at cell (i, j)
        dp = [[set() for _ in range(m)] for _ in range(n)]
        dp[0][0].add(grid[0][0])

        for i in range(n):
            for j in range(m):
                for val in dp[i][j]:
                    if i + 1 < n:
                        dp[i + 1][j].add(val ^ grid[i + 1][j])
                    if j + 1 < m:
                        dp[i][j + 1].add(val ^ grid[i][j + 1])

        return min(dp[n - 1][m - 1])