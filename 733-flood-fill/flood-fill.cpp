class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int og, vector<vector<bool>>& vis){
        vis[sr][sc] = true;
        image[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        int xx[4] = {0, 0, -1, 1};
        int yy[4] = {1, -1, 0, 0};

        for(int k=0; k<4; k++){
            int i = sr + xx[k];
            int j = sc + yy[k];

            if(0<=i && 0<=j && i<n && j<m){
                if(!vis[i][j] && image[i][j] == og) dfs(image, i, j, color, og, vis);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(image, sr, sc, color, image[sr][sc], vis);

        return image;
    }
};