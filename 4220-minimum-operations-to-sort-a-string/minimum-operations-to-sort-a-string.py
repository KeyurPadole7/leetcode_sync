class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        if all(s[i]<=s[i+1] for i in range(n-1)):
            return 0
        if n==2:
            return -1

        mn = min(s)
        mx = max(s)

        if mn==s[0] or mx==s[-1]:
            return 1
        elif mn==s[-1] and mx==s[0] and s.count(mx) == 1 and s.count(mn) == 1:
            return 3
        else:
            return 2
