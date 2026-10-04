class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j==0 || i==0) dp[i][j] = matrix[i][j];
                else if(matrix[i][j]==1) dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                else dp[i][j] = 0;
                
                sum+=dp[i][j];
            }
        }

        return sum;
    }
};