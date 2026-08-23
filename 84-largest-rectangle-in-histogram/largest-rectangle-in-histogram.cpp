class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> sl(n, 0);
        vector<int> sr(n, 0);

        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(s.empty()) sl[i] = -1;
            else sl[i] = s.top();
            s.push(i);
        }

        s = stack<int>();

        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(s.empty()) sr[i] = n;
            else sr[i] = s.top();
            s.push(i);
        }

        int mxarea = 0;
        for(int i=0; i<n; i++){
            mxarea = max(mxarea, arr[i]*(sr[i]-sl[i]-1));
        }
        return mxarea;
    }
};