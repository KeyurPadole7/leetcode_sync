import sys

# Increase recursion depth for deep trees
sys.setrecursionlimit(200000)

class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        s_chars = list(s)
        
        # Binary Lifting and Euler Tour Setup
        LOG = 17
        up = [[0] * LOG for _ in range(n)]
        depth = [0] * n
        tin = [0] * n
        tout = [0] * n
        timer = 0
        base_x = [0] * n
        
        def dfs(u: int, p: int, current_mask: int):
            nonlocal timer
            timer += 1
            tin[u] = timer
            up[u][0] = p
            for k in range(1, LOG):
                up[u][k] = up[up[u][k - 1]][k - 1]
                
            char_mask = 1 << (ord(s_chars[u]) - ord('a'))
            current_mask ^= char_mask
            base_x[u] = current_mask
            
            for v in adj[u]:
                if v != p:
                    depth[v] = depth[u] + 1
                    dfs(v, u, current_mask)
                    
            tout[u] = timer
            
        dfs(0, 0, 0)
        
        def get_lca(u: int, v: int) -> int:
            if depth[u] < depth[v]:
                u, v = v, u
            diff = depth[u] - depth[v]
            for k in range(LOG):
                if (diff >> k) & 1:
                    u = up[u][k]
            if u == v:
                return u
            for k in range(LOG - 1, -1, -1):
                if up[u][k] != up[v][k]:
                    u = up[u][k]
                    v = up[v][k]
            return up[u][0]

        # Fenwick Tree for Range XOR Update / Point Query
        bit = [0] * (n + 2)
        
        def bit_update(idx: int, val: int):
            while idx <= n:
                bit[idx] ^= val
                idx += idx & (-idx)
                
        def bit_query(idx: int) -> int:
            res = 0
            while idx > 0:
                res ^= bit[idx]
                idx -= idx & (-idx)
            return res

        def get_curr_x(u: int) -> int:
            return base_x[u] ^ bit_query(tin[u])

        ans = []
        for q in queries:
            parts = q.split()
            if parts[0] == "update":
                u = int(parts[1])
                new_c = parts[2]
                old_c = s_chars[u]
                if old_c != new_c:
                    delta = (1 << (ord(old_c) - ord('a'))) ^ (1 << (ord(new_c) - ord('a')))
                    # Range update [tin[u], tout[u]]
                    bit_update(tin[u], delta)
                    bit_update(tout[u] + 1, delta)
                    s_chars[u] = new_c
            else:
                u = int(parts[1])
                v = int(parts[2])
                lca = get_lca(u, v)
                lca_mask = 1 << (ord(s_chars[lca]) - ord('a'))
                path_xor = get_curr_x(u) ^ get_curr_x(v) ^ lca_mask
                
                # Check if at most one bit is set
                can_form_palindrome = (path_xor & (path_xor - 1)) == 0
                ans.append(can_form_palindrome)
                
        return ans