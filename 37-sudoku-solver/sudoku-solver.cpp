class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check entire row and column
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
        }

        // Check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == c) return false;
            }
        }
        return true;
    }

    bool ss(vector<vector<char>>& board, int row, int col) {
        // Base case: completed all rows
        if (row == 9) return true;

        // Move to the next row when at the end of the current row
        if (col == 9) return ss(board, row + 1, 0);

        // If cell is already filled, advance to the next cell
        if (board[row][col] != '.') return ss(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (issafe(board, row, col, c)) {
                board[row][col] = c;
                
                // Advance to next column; if path succeeds, propagate true
                if (ss(board, row, col + 1)) return true;
                
                // Backtrack on failure
                board[row][col] = '.';
            }
        }
        
        return false; // Trigger backtracking to previous cell
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        ss(board, 0, 0);
    }
};