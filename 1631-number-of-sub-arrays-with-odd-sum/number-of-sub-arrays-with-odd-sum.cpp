/*class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(prefix[i]%2==1) count++;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((prefix[j]-prefix[i])%2==1) count++;
            }
        }

        return count;
    }
};*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        int even = 1, odd = 0;
        int parity = 0;
        int count = 0;

        for(int x : arr) {
            parity = (parity + x) % 2;

            if(parity == 1) {
                count = (count + even) % MOD;
                odd++;
            }
            else {
                count = (count + odd) % MOD;
                even++;
            }
        }

        return count;
    }
};