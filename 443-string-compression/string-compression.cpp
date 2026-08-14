class Solution {
public:
    int compress(vector<char>& c) {
        stack<int> stk;
        string ans = "";
        int count;

        for(int i = 0; i<c.size(); i++){
            count = 1;
            ans.push_back(c[i]);
            while(i<c.size()-1 && c[i] == c[i+1]){
                count++;
                i++;
            }
            if(count>=10){
                while(count != 0){
                    stk.push(count%10);
                    count /= 10;
                }
                while(!stk.empty()){
                    ans.push_back(stk.top()+'0');
                    stk.pop();
                }
            }
            else if(count!=1) ans.push_back(count+'0');
        }

        cout<<ans;

        for(int i = 0; i<ans.size(); i++){
            c[i] = ans[i];
        }

        return ans.size();
    }
};