class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        others = "#"*(n-1)
        others += "."

        ans = [others for i in range(m)]
        ans[0] = "."*n
        return ans
