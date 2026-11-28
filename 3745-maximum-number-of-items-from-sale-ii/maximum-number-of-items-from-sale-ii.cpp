class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0); // factor value -> count of items with this factor
        vector<int> divcnt(n + 1, 0); // factor value -> count of OTHER items divisible by it
        int mncost = INT_MAX;

        // count frequencies and find minimum price (for 1-for-1 fallback buys)
        for(int i = 0; i < n; i++){
            freq[items[i][0]]++;
            if(mncost > items[i][1]){
                mncost = items[i][1];
            }
        }

        // O(n log n) sieve to count multiples of each factor
        for(int v = 1; v <= n; v++){
            if(freq[v] == 0) continue;
            for(int mul = v; mul <= n; mul += v){
                divcnt[v] += freq[mul];
            }
            divcnt[v]--; // exclude itself (i != j)
        }

        // sort items by price ascending so we greedily buy cheapest 2-for-1 copies first
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        long long rem = budget;
        long long ans = 0;

        // take 2-for-1 copies while price < 2 * mncost
        for(int i = 0; i < n; i++){
            long long f = items[i][0];
            long long p = items[i][1];
            long long slots = divcnt[f]; // max copies of item i that give a free item

            if(slots == 0) continue;
            if(p >= 2LL * mncost) break; // cheaper to just buy two mncost items instead

            long long can_buy = min(slots, rem / p);
            if(can_buy > 0){
                // check edge case: if we take one less 2-for-1 copy, can mncost buy more total items?
                long long opt1 = ans + can_buy * 2 + (rem - can_buy * p) / mncost;
                long long opt2 = ans + (can_buy - 1) * 2 + (rem - (can_buy - 1) * p) / mncost;

                if(opt2 > opt1){
                    can_buy--;
                    ans += can_buy * 2;
                    rem -= can_buy * p;
                    break; // stop taking 2-for-1s, spend rest on mncost
                }

                ans += can_buy * 2;
                rem -= can_buy * p;
            }
        }

        // spend whatever budget is left on the cheapest single item
        ans += rem / mncost;

        return (int)ans;
    }
};