/*class Solution { //Wrong implementaion;
public:
    int longestValidParentheses(string s) {
        int open=0;
        int mx=0;
        int count;

        for(int i=0; i<s.size(); i++){
            count=0;
            while(i<s.size()){
                if(s[i]=='('){
                    open++;
                    count++;
                }
                else if(open>0){
                    open--;
                    count++;
                }else{
                    break;
                }
                i++;
                if(open==0){
                    mx = max(mx, count);
                }
            }
        }

        return mx;
    }
};*/


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.size();
        int mx = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    mx = max(mx, i - st.top());
                }
            }
        }

        return mx;
    }
};