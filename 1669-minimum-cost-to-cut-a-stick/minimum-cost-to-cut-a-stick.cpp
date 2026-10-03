/*class Solution { //Memoization
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = 1e9;
        for(int idx=i; idx<=j; idx++){
            int cost = cuts[j+1] - cuts[i-1];
            cost += f(i, idx-1, cuts, dp) + f(idx+1, j, cuts, dp);
            
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        
        return f(1, c, cuts, dp);
    }
};*/


class Solution { 
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int c = cuts.size();

        vector<vector<int>> dp(c, vector<int>(c, 0));

        for(int i=c-1; i>=1; i--){
            for(int j=i; j<=c-2; j++){
                int mini = 1e9;
                for(int idx=i; idx<=j; idx++){
                    int cost = cuts[j+1] - cuts[i-1];
                    cost += dp[i][idx-1]+ dp[idx+1][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }
        return dp[1][c-2];
    }
};