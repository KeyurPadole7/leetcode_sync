class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            int ch = s[i] - 'a';
            sum += (i+1)*(26-ch);
        }

        return sum;
    }
};