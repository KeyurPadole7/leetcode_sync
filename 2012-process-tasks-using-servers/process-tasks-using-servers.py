import heapq

class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:

        n, m = len(servers), len(tasks)

        available = [(servers[i], i) for i in range(n)]
        heapq.heapify(available)

        busy = []
        ans = [0] * m

        time = 0

        for j in range(m):

            time = max(time, j)

            # Move all servers that have become free
            while busy and busy[0][0] <= time:
                free_time, weight, idx = heapq.heappop(busy)
                heapq.heappush(available, (weight, idx))

            # If no server is free, jump to the next free time (just to optimize code)
            if not available:
                time = busy[0][0]

                while busy and busy[0][0] <= time:
                    free_time, weight, idx = heapq.heappop(busy)
                    heapq.heappush(available, (weight, idx))

            # Assign the task to the best available server
            weight, idx = heapq.heappop(available)

            ans[j] = idx

            heapq.heappush(
                busy,
                (time + tasks[j], weight, idx)
            )

        return ans