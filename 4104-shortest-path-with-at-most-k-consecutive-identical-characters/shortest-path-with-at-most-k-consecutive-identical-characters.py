import heapq
from collections import defaultdict

class Solution:
    def shortestPath(self, n: int, edges: list[list[int]], labels: str, k: int) -> int:

        adj = [[] for _ in range(n)]

        for u, v, w in edges:
            adj[u].append((v, w))

        INF = float('inf')

        # dist[node][count]
        dist = [[INF] * (k + 1) for _ in range(n)]

        # Initially at node 0, count = 1
        dist[0][1] = 0

        # (cost, node, consecutive_count)
        pq = [(0, 0, 1)]

        while pq:
            cost, u, cnt = heapq.heappop(pq)

            if cost > dist[u][cnt]:
                continue

            # Destination reached
            if u == n - 1:
                return cost

            for v, w in adj[u]:

                # Same character: increase count
                if labels[u] == labels[v]:
                    new_cnt = cnt + 1
                else:
                    # Different character: reset count
                    new_cnt = 1

                # Invalid consecutive sequence
                if new_cnt > k:
                    continue

                new_cost = cost + w

                if new_cost < dist[v][new_cnt]:
                    dist[v][new_cnt] = new_cost
                    heapq.heappush(pq, (new_cost, v, new_cnt))

        return -1