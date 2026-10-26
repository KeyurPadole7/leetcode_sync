class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        ans =[[1]]

        for _ in range(numRows-1):
            row = [1]
            for i in range(1, len(ans[-1])):
                row.append(ans[-1][i-1]+ans[-1][i])
            row.append(1)
            ans.append(row)

        return ans