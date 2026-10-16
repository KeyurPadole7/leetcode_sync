/*class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int sum = 0;

        for(int i=0; i<n; i++){
            unordered_set<int> s;
            int count=0;
            for(int j=i; j<n; j++){
                if(!s.contains(nums[j])){
                    count++;
                    s.insert(nums[j]);
                }
                sum = (sum%mod + (count%mod)*(count%mod))%mod;
            }
        }

        return sum;
    }
};*/

/*class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int sum = 0;

        for(int i=0; i<n; i++){
            vector<bool> vis(100001, false);
            int count=0;
            for(int j=i; j<n; j++){
                if(!vis[nums[j]]){
                    count++;
                    vis[nums[j]] = true;
                }
                sum = (sum%mod + 1LL*(count%mod)*(count%mod))%mod;
            }
        }

        return sum;
    }
};*/

#include <vector>
using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    vector<long long> sum1; // Stores sum of elements (x)
    vector<long long> sum2; // Stores sum of squares (x^2)
    vector<long long> lazy; // Lazy propagation array

    // Helper to apply adding 'val' to a node covering range [l, r]
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        
        // Update sum of squares: sum(x^2) + 2*val*sum(x) + len*val^2
        long long term1 = (2LL * val % MOD * sum1[node]) % MOD;
        long long term2 = (len * (val * val % MOD)) % MOD;
        sum2[node] = (sum2[node] + term1 + term2) % MOD;

        // Update regular sum: sum(x) + len*val
        sum1[node] = (sum1[node] + len * val) % MOD;

        // Store lazy value for children
        lazy[node] = (lazy[node] + val) % MOD;
    }

    // Push lazy values down to children
    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    // Range update: add 1 to all elements in [ql, qr]
    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) update(node * 2, l, mid, ql, qr, val);
        if (qr > mid) update(node * 2 + 1, mid + 1, r, ql, qr, val);

        sum1[node] = (sum1[node * 2] + sum1[node * 2 + 1]) % MOD;
        sum2[node] = (sum2[node * 2] + sum2[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum1.assign(4 * n, 0);
        sum2.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        // Track last seen index of each number (values up to 100,000)
        vector<int> last_pos(100001, -1);
        long long total_ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last_pos[nums[j]];
            
            // Increment distinct count for all subarrays starting in [prev + 1, j]
            update(1, 0, n - 1, prev + 1, j, 1);
            
            // sum2[1] holds the sum of squares of distinct counts for all i <= j
            total_ans = (total_ans + sum2[1]) % MOD;
            
            last_pos[nums[j]] = j;
        }

        return total_ans;
    }
};