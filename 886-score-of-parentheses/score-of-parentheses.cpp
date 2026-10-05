class Solution {
public:
    int f(int i, int j, string &s){
        if(i>j) return 1;

        int count = 0;
        int open=0;
        for(int k=i; k<=j; k++){
            if(s[k]=='(') open++;
            else open--;
            
            if(open==0){
                count += 2*(f(i+1, k-1, s));
                i=k+1;
            }
        }

        return count;

    }
    int scoreOfParentheses(string s) {
        int n = s.size();
        return f(0, n-1, s)/2;
    }
};