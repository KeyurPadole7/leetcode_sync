class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int count = 0;
        for(auto c: s){
            if(c=='(') open++;
            else if(open==0) count++;
            else open--;
        }
        return count+open;
    }
};