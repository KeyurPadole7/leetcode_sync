class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int row = grid.size();
        int coln = grid[0].size();

        vector<int> temp;   
        temp.reserve(row*coln);

        for(int i = 0; i<row; i++){
            for(int j = 0; j<coln; j++){
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(), temp.end());

        vector<int> ans;
        ans.reserve(2);
        int a;
        int b;

        if(temp[0] == 2) b = 1;
        if(temp[row*coln-1] == row*coln-1) b = row*coln;

        for(int i = 0; i<row*coln-1; i++){
            if(temp[i] == temp[i+1]) a = temp[i];
            if(temp[i+1]-temp[i]==2) b = temp[i] + 1;
        }

        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};