class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.size();
        int mid = n / 2;
        
        int diff_sum = 0;
        int diff_q = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                if (num[i] == '?') {
                    diff_q++;
                } else {
                    diff_sum += (num[i] - '0');
                }
            } else {
                if (num[i] == '?') {
                    diff_q--;
                } else {
                    diff_sum -= (num[i] - '0');
                }
            }
        }
        
        // If remaining question mark count difference is odd, Alice always wins
        if (diff_q % 2 != 0) {
            return true;
        }
        
        // Bob wins iff 2 * diff_sum + 9 * diff_q == 0
        return (2 * diff_sum + 9 * diff_q) != 0;
    }
};