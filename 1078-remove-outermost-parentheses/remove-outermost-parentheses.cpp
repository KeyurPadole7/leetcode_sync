/*class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans;

        for(int i=0; i<s.length(); i++){
            if(open==0){
                int j=i+1;
                open++;
                while(open>0){
                    if(s[j]=='(') open++;
                    else open--;
                    j++;
                }

                if(j-i>2) ans.append(s, i+1, j-i-2);
                i=j;
            }
        }

        return ans;
    }
};*/


class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans;

        for(int i=0; i<s.length(); i++){
            int j=i;
            while(j==i || open>0){
                if(s[j]=='(') open++;
                else open--;
                j++;
            }

            if(j-i>2) ans.append(s, i+1, j-i-2);
            i=j-1;
        }

        return ans;
    }
};