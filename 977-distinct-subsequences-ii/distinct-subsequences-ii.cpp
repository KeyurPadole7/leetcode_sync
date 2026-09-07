class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        vector<long long> last(26, 0);
        long long total = 1; // Base case: includes the empty string ""

        for (char c : s) {
            int idx = c - 'a';
            long long new_added = total;
            
            total = (total * 2 - last[idx] + MOD) % MOD;
            last[idx] = new_added;
        }

        // Subtract 1 to exclude the empty subsequence
        return (total - 1 + MOD) % MOD;
    }
};