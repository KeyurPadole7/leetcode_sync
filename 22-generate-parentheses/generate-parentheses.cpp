class Solution {
public:
    void f(int open, int close, int flag, string s, vector<string> &ans){
        if(close==0 && open!=0) return;
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if(open!=0) f(open-1, close, flag+1, s+'(', ans);
        if(close!=0 && flag>0) f(open, close-1, flag-1, s+')', ans);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        f(n, n, 0, s, ans);
        return ans;
    }
};