class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)

        weights = [1] * n

        for i in range(n):
            for j in range(n):
                if i != j and items[j][0] % items[i][0] == 0:
                    weights[i] += 1

        groups = {}

        for i in range(n):
            p = items[i][1]
            groups.setdefault(p, []).append(weights[i])

        dp = [-1] * (budget + 1)
        dp[0] = 0

        ans = 0

        for p in sorted(groups, reverse=True):
            dp1 = [-1] * (budget + 1)

            for w in groups[p]:
                for c in range(budget, p - 1, -1):
                    if dp1[c - p] != -1:
                        dp1[c] = max(dp1[c], dp1[c - p] + w)

                    if dp[c - p] != -1:
                        dp1[c] = max(dp1[c], dp[c - p] + w)

            for c in range(budget + 1):
                if dp1[c] != -1:
                    extra = (budget - c) // p
                    ans = max(ans, dp1[c] + extra)

            for c in range(budget + 1):
                dp[c] = max(dp[c], dp1[c])

        return ans