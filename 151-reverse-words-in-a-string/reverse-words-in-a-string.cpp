class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        string word = "";
        string ans = "";

        for(int i = 0; i < n; i++){
            word = "";
            while(i<n && s[i] != ' ')  word += s[i++];

            reverse(word.begin(), word.end());
            if(word.size()>0) ans += " " + word;
        }
        return ans.substr(1);
    }
};