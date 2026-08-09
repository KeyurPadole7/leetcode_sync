class Solution {
public:
    int r[4] = {1,-1,0,0};
    int l[4] = {0,0,1,-1};

    bool helper(int row, int coln, vector<vector<char>>& board, string word, int n, int m, int size, int index){
        if(size == index) return true;
        char ch = board[row][coln];
        board[row][coln] = '$';

        for(int i = 0; i<4; i++){
            int ud = row + r[i];
            int rl = coln + l[i];

            if(ud>=0 && rl>=0 && ud<n && rl<m){
                if(board[ud][rl] == word[index]){
                    if(helper(ud, rl, board, word, n, m, size, index+1)) return true;
                }
            }
        }
        board[row][coln] = ch;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int size = word.size(); 
        int index = 0;
        char ch = word[0];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(ch == board[i][j]){
                    if(helper(i, j, board, word, n, m, size, index+1)) return true;
                }
            }
        }

        return false;
    }
};