class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }

        int time = 0;

        int xx[4] = {0, 0, 1, -1};
        int yy[4] = {1, -1, 0, 0};

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int currtime = q.front().second;
            time = max(time, currtime);

            q.pop();

            for(int k=0; k<4; k++){
                int newi = i + xx[k];
                int newj = j + yy[k];

                if(0<=newi && 0<=newj && newi<n && newj<m){
                    if(grid[newi][newj] == 1 && !vis[newi][newj]){
                        vis[newi][newj] = true;
                        q.push({{newi, newj}, currtime+1});
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }

        return time;

    }
};