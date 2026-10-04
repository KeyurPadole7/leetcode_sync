/*class Solution {
public:
    int sol = INT_MAX;

    bool ispal(string &s, int st, int fin){
        while(st<fin){
            if(s[st] != s[fin]) return false;
            st++; fin--;
        }
        return true;
    }

    void pal(string &s, int st, int count){
        int n = s.size();
        if(st == n){
            sol = min(sol, count-1);
            return;
        }

        for(int i=st; i<n; i++){
            if(ispal(s, st, i)){
                pal(s, i+1, count+1);
            }
        }
    }

    int minCut(string s) {
        pal(s, 0, 0);
        return sol;
    }
};*/

class Solution {
public:
    bool ispal(int st, int end, string &s){
        while(st<end){
            if(s[st++]!=s[end--]) return false;
        }
        return true;
    }

    int f(int i, int j, string &s, vector<vector<int>> &dp){
        if(ispal(i, j, s)) return 0;
        if(i==j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int mn = 1e9;
        for(int cut=i; cut<j; cut++){
            if(ispal(i, cut, s)){
                int count = 1 + f(i, cut, s, dp) + f(cut+1, j, s, dp);
                mn = min(mn, count);
            }
        }

        return dp[i][j] = mn;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n-1, s, dp);
    }
};