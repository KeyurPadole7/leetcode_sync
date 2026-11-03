class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue

                curr = board[i][j]
                for x in range(9):
                    if board[x][j] == curr:
                        if x == i:
                            continue
                        return False
                    if board[i][x] == curr:
                        if x == j:
                            continue
                        return False

                for x in range((i//3)*3, (i//3)*3+3):
                    for y in range((j//3)*3, (j//3)*3+3):
                        if x==i and y==j:
                            continue
                        if board[x][y] == curr:
                            return False

        return True