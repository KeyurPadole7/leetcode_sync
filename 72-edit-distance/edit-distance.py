class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        # dp = [[-1]*m for _ in range(n)]

        # def f(i, j):
        #     if i<0:
        #         return j+1
        #     if j<0:
        #         return i+1

        #     if(dp[i][j] != -1):
        #         return dp[i][j]
        #     mn = 10**9+7
        #     if(word1[i] == word2[j]):
        #         mn = min(mn, f(i-1, j-1))
        #     mn = min(mn, 1 + f(i-1, j))  # Delete
        #     mn = min(mn, 1 + f(i, j-1))  # Insert
        #     mn = min(mn, 1 + f(i-1, j-1))  # Replace

        #     dp[i][j] = mn
        #     return mn
            
        # ans = f(len(word1)-1, len(word2)-1)
        # print(dp)
        # return ans

        dp = [[0]*(m+1) for _ in range(n+1)]
        for j in range(m+1):
            dp[0][j] = j
        for i in range(n+1):
            dp[i][0] = i        
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                if(word1[i-1] == word2[j-1]):
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    )           
        return dp[n][m]
