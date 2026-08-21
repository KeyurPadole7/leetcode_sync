#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Counts numbers <= m that are divisible by at least one coin
    long long countMultiples(long long m, const vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // Iterate through all non-empty subsets (1 to 2^n - 1)
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bit_count = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bit_count++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    if (current_lcm > m) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (bit_count % 2 == 1) {
                count += m / current_lcm;
            } else {
                count -= m / current_lcm;
            }
        }

        return count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};