class Solution {
public:
    int f(vector<int> &row){
        int n = row.size();
        vector<int> rmin(n, n);
        vector<int> lmin(n, -1);

        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && row[st.top()] >= row[i]){
                st.pop();
            }
            if(!st.empty()) rmin[i] = st.top();
            st.push(i);
        }


        st = {};
        for(int i=0; i<n; i++){
            while(!st.empty() && row[st.top()] >= row[i]){
                st.pop();
            }
            if(!st.empty()) lmin[i] = st.top();
            st.push(i);
        }


        int mx = -1e9;
        for(int i=0; i<n; i++){
            int area = row[i]*(rmin[i]-lmin[i]-1);
            mx = max(mx, area);
        }

        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(m, 0);

        int mxarea = -1e9;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0') row[j] = 0;
                else row[j]+=1;
            }
            mxarea = max(mxarea, f(row));
        }
        
        return mxarea;
    }
};