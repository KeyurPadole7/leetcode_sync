class Solution {
public:
    int f(int i, int j, string &w1, string &w2, vector<vector<int>> &dp){
        if(i==0) return j;
        if(j==0) return i;

        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i-1]==w2[j-1]) return dp[i][j] = f(i-1, j-1, w1, w2, dp);
        else return dp[i][j] = 1 + min(f(i, j-1, w1, w2, dp), min(f(i-1, j, w1, w2, dp), f(i-1, j-1, w1, w2, dp)));
        
    }
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, w1, w2, dp);
    }
};