class Solution {
public:
    int strStr(string ls, string ss) {
        if(ls.size()<=ss.size()) return ls==ss ? 0 : -1;

        int n = ls.size();
        int m = ss.size();

        for(int i=0; i<ls.length(); i++){
            int j=0;
            while(ls[i+j]==ss[j]){
                if(j==m-1) return i;
                j++;
            }
        }

        return -1;
    }
};