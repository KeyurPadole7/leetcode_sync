class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        deque<int> dq;
        string sub = "";

        for(int i=0; i<s.size(); i++){
            while(i<s.size() && dq.size()<k){
                if(s[i] == '1') dq.push_back(i);
                i++;
            }
            i--;

            if(dq.size() == k){
                string temp = s.substr(dq.front(), dq.back()-dq.front()+1);
                if(sub.empty() ||
                    temp.size() < sub.size() ||
                    (temp.size() == sub.size() && temp < sub)) sub = temp;
                dq.pop_front();
            }
        }


        return sub;
    }
};