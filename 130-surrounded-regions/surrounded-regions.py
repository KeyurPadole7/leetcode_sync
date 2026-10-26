class Solution:
    def solve(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n = len(board)
        m = len(board[0])

        def edgedfs0(r,c):
            if(r<0 or c<0 or r>=n or c>=m or board[r][c]!='O'):
                return
            
            board[r][c] = '0'
            edgedfs0(r+1,c)
            edgedfs0(r-1,c)
            edgedfs0(r,c+1)
            edgedfs0(r,c-1)

        
        for i in range(n):
            if board[i][0] == 'O':
                edgedfs0(i,0)
            if board[i][m-1] == 'O':
                edgedfs0(i,m-1)


        for j in range(m):
            if board[0][j] == 'O':
                edgedfs0(0,j)
            if board[n-1][j] == 'O':
                edgedfs0(n-1,j)


        for i in range(n):
            for j in range(m):
                if(board[i][j] == '0'):
                    board[i][j] = 'O'
                elif(board[i][j] == 'O'):
                    board[i][j] = 'X'
        
        

