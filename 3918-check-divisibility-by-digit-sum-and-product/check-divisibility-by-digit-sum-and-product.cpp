class Solution {
public:
    bool checkDivisibility(int num) {
        int sum=0,prod=1;
        int n = num;

        while(n!=0){
            sum += n%10;
            prod*= n%10;
            n /= 10;
        }
        if(num%(sum+prod) == 0) return true;
        else return false;
    }
};