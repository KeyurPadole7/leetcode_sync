class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2) return 0;
        vector<bool> isprime(n,true);
        int multby;
        int count = 0;

        for(int i=2; i<n; i++){
            if(isprime[i]){
                count++;
                multby = 2;
                while(i*multby < n) isprime[(multby++)*i] = false;
            }
        }

        return count;
    }
};