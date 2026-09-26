class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> um;
        for(auto pr: knowledge){
            um[pr[0]] = pr[1];
        }

        string ans;

        for(int i=0; i<s.size(); i++){
            if(s[i] != '('){
                ans += s[i];
                continue;
            }
            string temp;
            i++;

            while(s[i] != ')') temp+=s[i++];

            if(um.contains(temp)) ans += um[temp];
            else ans += '?';

        } 

        return ans;
    }
};