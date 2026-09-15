class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        int n = s.size();
        int count = 0;
        int last_end = -1;

        auto is_palindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        };

        for (int i = k - 1; i < n; ++i) {
            // Check length k
            if (i - k + 1 > last_end && is_palindrome(i - k + 1, i)) {
                count++;
                last_end = i;
            }
            // Check length k + 1
            else if (i - k > last_end && is_palindrome(i - k, i)) {
                count++;
                last_end = i;
            }
        }

        return count;
    }
};