/*class Solution {
public:
    bool f(int idx, string &s, stack<char> st){
        if(idx == s.size()) return st.empty();

        bool flag = false;
        if(s[idx] == '('){
            st.push('(');
            flag = f(idx+1, s, st);
        }else if(s[idx] == ')'){
            if(st.empty()) return false;
            st.pop();
            flag = f(idx+1, s, st);
        }else{
            flag = f(idx+1, s, st);
            st.push('(');
            flag = flag || f(idx+1, s, st);
            st.pop();
            if(!st.empty()){
                st.pop();
                flag = flag || f(idx+1, s, st);
                st.push('(');
            }
        }

        return flag;
    }
    bool checkValidString(string s) {
        stack<char> st;
        return f(0, s, st);
    }
};*/

class Solution {
public:
    bool f(int idx, string &s, int st, vector<vector<int>> &dp){
        if(idx == s.size()) return st==0;

        if(dp[idx][st]!=-1) return dp[idx][st];

        bool flag = false;
        if(s[idx] == '(') flag = f(idx+1, s, st+1, dp);

        else if(s[idx] == ')'){
            if(st>0) flag = f(idx+1, s, st-1, dp);
        }
        
        else{
            flag = f(idx+1, s, st, dp); if(flag) return true;
            if(!flag)flag = f(idx+1, s, st+1, dp); if(flag) return true;
            if(!flag && st>0) flag = f(idx+1, s, st-1, dp);
        }

        return dp[idx][st] = flag;
        // return flag;
    }

    bool checkValidString(string s) {
        int n = s.size();
        int st = 0;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(0, s, st, dp);
    }
};


/*class Solution {
public:
    bool f(int idx, int open, string &s, vector<vector<int>> &dp) {
        if (idx == s.size()) return open == 0;
        if (dp[idx][open] != -1) return dp[idx][open];

        bool isValid = false;

        if (s[idx] == '(') {
            isValid = f(idx + 1, open + 1, s, dp);
        } else if (s[idx] == ')') {
            if (open > 0) {
                isValid = f(idx + 1, open - 1, s, dp);
            }
        } else { // s[idx] == '*'
            // 1. Treat '*' as empty string
            isValid = f(idx + 1, open, s, dp);
            // 2. Treat '*' as '('
            if (!isValid) isValid = f(idx + 1, open + 1, s, dp);
            // 3. Treat '*' as ')'
            if (!isValid && open > 0) isValid = f(idx + 1, open - 1, s, dp);
        }

        return dp[idx][open] = isValid;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, 0, s, dp);
    }
};*/