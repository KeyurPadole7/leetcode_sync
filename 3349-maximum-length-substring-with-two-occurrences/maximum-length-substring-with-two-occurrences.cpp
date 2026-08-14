class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> m(26,0);

        int j = 0;
        int mx = 0;

        for(int i=0; i<s.size(); i++){
            m[s[i]-'a']++;
            while(m[s[i]-'a'] > 2) m[s[j++]-'a']--;
            mx = max(mx, i-j+1);
        }
        return mx;
    }
};