class Solution {
public:
    vector<vector<string>> ans;
    bool issafe(vector<string>& board, int row, int coln, int n){
        for(int i = 0; i<n; i++) if(board[i][coln] == 'Q') return false;
        for(int j = 0; j<n; j++) if(board[row][j] == 'Q') return false;
        for(int i=row, j=coln; i>=0 && j>=0; i--, j--) if(board[i][j] == 'Q') return false;
        for(int i=row, j=coln; i>=0 && j<n; i--, j++) if(board[i][j] == 'Q') return false;
        return true;
    }

    void nqueens(vector<string>& board, int n, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(issafe(board, row, j, n)){
                board[row][j] = 'Q';
                nqueens(board, n, row+1);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n, '.'));
        nqueens(board, n, 0);
        return ans;
    }
};