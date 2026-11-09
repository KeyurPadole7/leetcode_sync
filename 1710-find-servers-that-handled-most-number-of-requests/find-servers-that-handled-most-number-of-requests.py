class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        import heapq

        size = 1
        while size < k:
            size *= 2

        tree = [0] * (2 * size)
        count = [0] * k
        busy = []

        # Initially, all servers are available
        for i in range(k):
            tree[size + i] = 1

        for i in range(size - 1, 0, -1):
            tree[i] = tree[2 * i] + tree[2 * i + 1]

        def update(server, value):
            idx = size + server
            tree[idx] = value

            idx //= 2
            while idx:
                tree[idx] = tree[2 * idx] + tree[2 * idx + 1]
                idx //= 2

        def find_server(start):
            if tree[1] == 0:
                return -1

            # Search [start, k)
            if start < k:
                result = search(start, k)
                if result != -1:
                    return result

            # Wrap around: search [0, start)
            return search(0, start)

        def search(left, right):
            # Find first available server in [left, right)
            def dfs(node, l, r):
                if r <= left or right <= l or tree[node] == 0:
                    return -1

                if r - l == 1:
                    return l

                mid = (l + r) // 2

                res = dfs(node * 2, l, mid)
                if res != -1:
                    return res

                return dfs(node * 2 + 1, mid, r)

            return dfs(1, 0, size)

        for i in range(len(arrival)):
            t = arrival[i]

            # Release completed servers
            while busy and busy[0][0] <= t:
                end, server = heapq.heappop(busy)
                update(server, 1)

            server = find_server(i % k)

            if server == -1:
                continue

            count[server] += 1
            update(server, 0)

            heapq.heappush(busy, (t + load[i], server))

        max_count = max(count)

        return [i for i in range(k) if count[i] == max_count]