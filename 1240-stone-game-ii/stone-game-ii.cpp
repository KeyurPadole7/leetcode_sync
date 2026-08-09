#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    int memo[101][101];
    std::vector<int> suffixSum;
    int n;

    int dp(int i, int M) {
        // Base case: If we can take all remaining piles in this move
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }

        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;

        // Try taking X piles where 1 <= X <= 2M
        for (int X = 1; X <= 2 * M; ++X) {
            int nextM = std::max(M, X);
            // Total remaining stones minus optimal opponent score
            int stones = suffixSum[i] - dp(i + X, nextM);
            maxStones = std::max(maxStones, stones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(std::vector<int>& piles) {
        n = piles.size();
        suffixSum.assign(n + 1, 0);

        // Precompute suffix sums
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Initialize memoization array with -1
        std::fill(&memo[0][0], &memo[0][0] + 101 * 101, -1);

        return dp(0, 1);
    }
};