class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxc = 0;
        int count = 0;

        unordered_set<char> uos;
        
        for(r = 0; r<s.size(); r++){// Shrink window until duplicate s[r] is removed
            while (uos.contains(s[r])) {
                uos.erase(s[l]);
                l++;
            }
            
            // Now s[r] can safely enter the window
            uos.insert(s[r]);
            maxc = std::max(maxc, r - l + 1);
        }

        return maxc;
    }

};