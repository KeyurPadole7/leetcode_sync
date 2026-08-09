class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int coln = matrix[0].size();

        vector<int> r;
        vector<int> c;

        for(int i = 0; i<row; i++){
            for( int j = 0; j<coln; j++){
                if(matrix[i][j] == 0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }

        int k=0;
        int x;

        while(k<r.size()){
            x = r[k];
            for(int i = 0; i<coln; i++){
                matrix[x][i] = 0;
            }
            k++;
        }

        k=0;

        while(k<c.size()){
            x = c[k];
            for(int i=0 ; i<row; i++){
                matrix[i][x] = 0;
            } 
            k++;
        }

        return ;
    }
};