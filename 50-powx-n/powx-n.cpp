class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if(n<0){
            x = 1/x;
            m = 0-m;
        }

        long long binform = m;
        double ans = 1;

        while(binform>0){
            if(binform%2!=0){
                ans *= x;
            }
            x *= x;
            binform /= 2;
        }

        return ans;
    }
};