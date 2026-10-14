class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num==1 && sum<10) return to_string(sum);
        if(sum>9*num) return "";

        string ans(sum/9, '9');
        if(sum%9!=0) ans += to_string(sum%9);

        ans.resize(num, '0');


        return ans;
    }
};