class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> r(n,0);
        vector<int> l(n,0);

        for(int i = 0; i < n; i++){
            while(s.size()>0 && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) l[i] = -1;
            else l[i] = s.top();
            s.push(i);
        }

        s = {};

        for(int i = n-1; i>=0; i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) r[i] = -1;
            else r[i] = s.top();
            s.push(i);
        }

        int maxarea = 0;
        int width;
        int right;
        int area;

        for(int i=0; i<n; i++){
            if(r[i] == -1) right = n;
            else right = r[i];
            width = right - l[i] - 1;
            area = heights[i] * width;
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};