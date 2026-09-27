// class Solution {
// public:
//     string helper(int &j, string s){
//         j++;
//         string temp;
//         while(j<s.size()){
//             if(s[j] == '(') temp += helper(j, s);
//             else if(s[j] == ')'){
//                 //j++;
//                 break;
//             }else{
//                 temp += s[j];
//             }
//             j++;
//         }

//         reverse(temp.begin(), temp.end());
//         return temp;
//     }


//     string reverseParentheses(string s) {
//         int idx = 0;
//         string ans;
//         for(idx = 0; idx<s.size(); idx++){
//             if(s[idx] == '(') ans += helper(idx, s);
//             else ans += s[idx];
//         }
//         return ans;

//     }
// };


class Solution {
public:
    string reverseParentheses(string str) {
        stack<string> s;
        string curr;

        for(char c: str){
            if(c == '('){
                s.push(curr);
                curr.clear();
            }
            else if(c == ')'){
                reverse(curr.begin(), curr.end());
                curr = s.top() + curr;
                s.pop();
            }else{
                curr += c;
            }
        }

        return curr;
    }
};