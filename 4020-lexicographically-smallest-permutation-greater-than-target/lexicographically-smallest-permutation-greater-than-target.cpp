class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        if (s.size() != target.size()) return "";

        vector<int> total_count(26, 0);
        for (char c : s) {
            total_count[c - 'a']++;
        }

        // Iterate backwards to find the longest matching prefix
        for (int i = n - 1; i >= 0; i--) {
            vector<int> count = total_count;
            bool can_match_prefix = true;

            // Check if s can form the prefix target[0...i-1]
            for (int j = 0; j < i; j++) {
                if (--count[target[j] - 'a'] < 0) {
                    can_match_prefix = false;
                    break;
                }
            }

            if (!can_match_prefix) continue;

            // Find the smallest available character strictly greater than target[i]
            for (int c = (target[i] - 'a') + 1; c < 26; c++) {
                if (count[c] > 0) {
                    string ans = target.substr(0, i);
                    ans.push_back('a' + c);
                    count[c]--;

                    // Append the rest in ascending alphabetical order
                    for (int k = 0; k < 26; k++) {
                        while (count[k] > 0) {
                            ans.push_back('a' + k);
                            count[k]--;
                        }
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};