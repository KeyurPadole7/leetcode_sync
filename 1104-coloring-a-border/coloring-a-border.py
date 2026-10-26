class Solution:
    def colorBorder(self, grid: list[list[int]], row: int, col: int, color: int) -> list[list[int]]:
        n, m = len(grid), len(grid[0])
        vis = set()
        put = []

        def dfs(r, c):
            vis.add((r,c))
            is_border = False
            
            for dr, dc in [(0,1), (1,0), (0,-1), (-1,0)]:
                nr, nc = r+dr, c+dc
                if not (0<=nr<n and 0<=nc<m):
                    is_border = True
                elif grid[nr][nc] != grid[row][col]:
                    is_border = True
                elif (nr,nc) not in vis:
                    dfs(nr, nc)

            if is_border:
                put.append((r,c))

        dfs(row, col)

        for r,c in put:
            grid[r][c] = color

        return grid
