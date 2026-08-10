class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), coln = matrix[0].size();
        int srow = 0, scol = 0;
        int erow = row - 1, ecol = coln - 1;

        vector<int> ans;

        while(srow<=erow && scol<=ecol){
            //Top
            for(int j = scol; j<=ecol; j++){
                ans.push_back(matrix[srow][j]);
            }

            //Right
            for(int i = srow+1; i<=erow; i++){
                ans.push_back(matrix[i][ecol]);
            }

            //Down
            for(int j = ecol-1; j>=scol; j--){
                if(srow == erow) break;
                ans.push_back(matrix[erow][j]);
            }

            //left
            for(int i = erow-1; i>=srow+1; i--){
                if(scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            srow++; scol++; erow--; ecol--;
        }
        return ans;
    }
};