class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        bool pos = true;
        bool spcbfr = true;
        int sol = 0;
        for(char c: s){
            if(c=='+'){
                if(spcbfr){
                    spcbfr = false;
                    continue;
                }
                else break;
            }
            if(c=='-' || c==' ' || ('0'<=c && c<='9')){
                if(!spcbfr && c == '-') break;
                if(spcbfr && c == '-'){
                    pos = false;
                    spcbfr = false;
                    continue;
                }
                if(spcbfr && c == '0'){
                    spcbfr = false;
                    continue;
                }
                if(spcbfr && c == ' '){
                    continue;
                }
                if(!spcbfr && c == ' ') break;
                num *= 10;
                num += c-'0';
                spcbfr = false;

                if(pos){
                    if(num>=pow(2,31))return sol = pow(2,31)-1;
                    else sol = num;
                }else{
                    if(-num < -pow(2,31))return sol = -pow(2,31);
                    else sol = -num;
                }
            }
            else{
                break;
            }
        }


        return sol;
    }
};