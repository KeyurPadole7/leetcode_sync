class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto ch: s){
            if(stk.empty()) stk.push(ch);
            else if(ch == ')' && stk.top() == '(') stk.pop();
            else if(ch == '}' && stk.top() == '{') stk.pop();
            else if(ch == ']' && stk.top() == '[') stk.pop();
            else stk.push(ch);
        }

        if(stk.empty()) return true;
        else return false;
    }
};