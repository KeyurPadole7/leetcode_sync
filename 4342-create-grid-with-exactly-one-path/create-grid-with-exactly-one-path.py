class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = ["."*n]
        for i in range(1,m):
            st = ""
            for j in range(n):
                if j == n-1:
                    st += '.'
                else:
                    st += "#"
            ans.append(st)

        return ans
