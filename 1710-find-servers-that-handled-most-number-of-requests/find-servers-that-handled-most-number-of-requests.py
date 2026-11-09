class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        available = list(range(k))
        heapq.heapify(available)

        busy = []
        count = [0] * k

        for i, start in enumerate(arrival):

            # Release completed servers
            while busy and busy[0][0] <= start:
                end_time, server = heapq.heappop(busy)

                virtual = i + (server - i) % k
                heapq.heappush(available, virtual)

            # Assign the next available server
            if available:
                server = heapq.heappop(available) % k

                heapq.heappush(busy, (start + load[i], server))
                count[server] += 1

        maximum = max(count)

        return [i for i in range(k) if count[i] == maximum]