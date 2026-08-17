class Solution {
public:
int memo[505][505];
    vector<int> prefix;

    int getSum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int l, int r, const vector<int>& stoneValue) {
        if (l >= r) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int maxScore = 0;

        for (int k = l; k < r; ++k) {
            int leftSum = getSum(l, k);
            int rightSum = getSum(k + 1, r);

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(l, k, stoneValue));
            } else if (leftSum > rightSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, r, stoneValue));
            } else {
                int takeLeft = leftSum + solve(l, k, stoneValue);
                int takeRight = rightSum + solve(k + 1, r, stoneValue);
                maxScore = max(maxScore, max(takeLeft, takeRight));
            }
        }

        return memo[l][r] = maxScore;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
            int n = stoneValue.size();
            memset(memo, -1, sizeof(memo));

            prefix.assign(n + 1, 0);
            for (int i = 0; i < n; ++i) {
                prefix[i + 1] = prefix[i] + stoneValue[i];
            }

            return solve(0, n - 1, stoneValue);
        }
};