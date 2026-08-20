class Solution {
public:
    bool isvalid(string s){
        if(s.size() == 0) return true;

        int l=0, r=s.size()-1;
        while(l<r) if(s[l++]!=s[r--]) return false;

        return true;
    }

    void pal(string s, vector<string> &prts, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(prts);
            return;
        }

        for(int i=0; i<s.size(); i++){
            if(isvalid(s.substr(0,i+1))){
                prts.push_back(s.substr(0,i+1));
                pal(s.substr(i+1, s.size()), prts, ans);
                prts.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> prts;

        pal(s, prts, ans);
        return ans;
    }
};