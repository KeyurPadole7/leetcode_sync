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

/*class Solution { //Memoization
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
};*/


class Solution {
public:
    bool checkValidString(string s) {
        int mnopen = 0;
        int mxopen = 0;

        for(char c: s){
            if(c == '('){
                mnopen++;
                mxopen++;
            }
            else if(c==')'){
                mnopen--;
                mxopen--;
            }
            else{
                mnopen--; // ")"
                mxopen++; // "("
            }

            if(mxopen<0) return false;
            if(mnopen<0) mnopen = 0;
        }
        return mnopen==0;
    }
};