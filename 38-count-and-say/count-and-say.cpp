class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string now = countAndSay(n-1);

        int len = now.size();
        string ans;
        for(int i=0; i<len; i++){
            int count = 1;
            while(i<len-1 && now[i]==now[i+1]){
                i++;
                count++;
            }
            ans+= to_string(count);
            ans+= now[i];
        }

        return ans;
    }
};