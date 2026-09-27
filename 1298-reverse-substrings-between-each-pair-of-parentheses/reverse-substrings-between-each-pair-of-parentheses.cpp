class Solution {
public:
    string helper(int &j, string s){
        j++;
        string temp;
        while(j<s.size()){
            if(s[j] == '(') temp += helper(j, s);
            else if(s[j] == ')'){
                //j++;
                break;
            }else{
                temp += s[j];
            }
            j++;
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }


    string reverseParentheses(string s) {
        int idx = 0;
        string ans;
        for(idx = 0; idx<s.size(); idx++){
            if(s[idx] == '(') ans += helper(idx, s);
            else ans += s[idx];
        }
        return ans;

    }
};