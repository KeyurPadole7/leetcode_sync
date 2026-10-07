class Solution {
public:
    void f(int i, int count, int open, string &s, string &sofar, vector<string> &ans, unordered_set<string> &os){
        if(open<0) return;

        if(i==s.size()){
            if(count == 0 && !os.contains(sofar) && open==0){
                ans.push_back(sofar);
                os.insert(sofar);
            }
            return;
        }

        if(count>0){ // Validity
            f(i+1, count-1, open, s, sofar, ans, os);
        }

        if(s[i] == ')') open--;
        if(s[i] == '(') open++;
        sofar += s[i];
        f(i+1, count, open, s, sofar, ans, os);
        sofar.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int open = 0;
        int count = 0;

        for(auto c: s){
            if(c!='(' && c!=')') continue;

            if(c == '(') open++;
            else if(open==0) count++;
            else open--;
        }

        count += open;
        cout<< count;

        vector<string> ans;
        string sofar;

        unordered_set<string> os;

        f(0, count, 0, s, sofar, ans, os);
        return ans;
    }
};