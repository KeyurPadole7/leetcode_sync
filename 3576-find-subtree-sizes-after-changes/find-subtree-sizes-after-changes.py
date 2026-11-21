
class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)

        # Build the original tree
        adj = [[] for _ in range(n)]

        for i in range(1, n):
            adj[parent[i]].append(i)

        # Store the new parent of every node
        new_parent = parent[:]

        # Last node having each character on current DFS path
        last = {}

        def dfs(node):
            ch = s[node]

            # Find nearest ancestor with same character
            if ch in last:
                new_parent[node] = last[ch]

            # Save current node
            prev = last.get(ch, -1)
            last[ch] = node

            for child in adj[node]:
                dfs(child)

            # Backtrack
            if prev == -1:
                del last[ch]
            else:
                last[ch] = prev

        dfs(0)

        # Build the modified tree
        new_adj = [[] for _ in range(n)]

        for i in range(1, n):
            new_adj[new_parent[i]].append(i)

        # Calculate subtree sizes
        ans = [1] * n

        def calculate(node):
            for child in new_adj[node]:
                calculate(child)
                ans[node] += ans[child]

        calculate(0)

        return ans
