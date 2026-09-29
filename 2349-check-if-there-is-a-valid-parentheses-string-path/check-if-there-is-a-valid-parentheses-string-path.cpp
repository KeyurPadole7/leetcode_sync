class Solution {
public:
    int f(int i, int j, int par, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
        // if(i==0 && j==0) return (par==1);
        if((i==0 && j<0) || (i<0 && j==0)) return (par==0);
        if(i<0 || j<0) return false;

        if(dp[i][j][par] != -1) return dp[i][j][par];

        bool down = false;
        bool right = false;

        if(grid[i][j]=='('){
            if(par>0){
                down = f(i-1, j, par-1, grid, dp);
                right = f(i, j-1, par-1, grid, dp);
            }
        }
        else{
            down = f(i-1, j, par+1, grid, dp);
            right = f(i, j-1, par+1, grid, dp);
        }

        return dp[i][j][par] = down | right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n+m, -1)));
        return f(n-1, m-1, 0, grid, dp);
    }
};