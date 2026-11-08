class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        ans = 0
        n, m = len(grid), len(grid[0])

        for i in range(n):
            count = 0
            solo = [0, 0]
            for j in range(m):
                if grid[i][j] == 1:
                    count += 1
                    grid[i][j] = -1
                    solo[0], solo[1] = i, j
            
            if count == 1:
                grid[solo[0]][solo[1]] = 1
            else:
                ans += count


        for j in range(m):
            realcount = 0
            count = 0
            solo = [0, 0]
            for i in range(n):
                if grid[i][j] == 1 or grid[i][j] == -1:
                    realcount += 1
                    if grid[i][j] == 1:
                        count += 1
                        grid[i][j] = -1
                        solo[0], solo[1] = i, j
                
            if realcount == 1 and count == 1:
                grid[solo[0]][solo[1]] = 1
            else:
                ans += count

        return ans
                