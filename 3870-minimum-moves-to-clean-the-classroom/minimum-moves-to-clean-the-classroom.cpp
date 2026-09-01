class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        pair<int, int> start;
        map<pair<int, int>, int> litter_map;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                char ch = classroom[r][c];
                if (ch == 'S') {
                    start = {r, c};
                } else if (ch == 'L') {
                    int id = litter_map.size();
                    litter_map[{r, c}] = id;
                }
            }
        }
        
        int total_litter = litter_map.size();
        if (total_litter == 0) return 0;
        
        int target_mask = (1 << total_litter) - 1;
        
        // max_energy[r][c][mask] stores the highest remaining energy seen so far
        vector<vector<vector<int>>> max_energy(
            m, vector<vector<int>>(n, vector<int>(1 << total_litter, -1))
        );
        
        // Queue elements: {row, col, mask, current_energy, moves}
        queue<tuple<int, int, int, int, int>> q;
        
        q.push({start.first, start.second, 0, energy, 0});
        max_energy[start.first][start.second][0] = energy;
        
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto [r, c, mask, cur_energy, moves] = q.front();
            q.pop();
            
            if (mask == target_mask) {
                return moves;
            }
            
            // Cannot branch further if out of energy and not on a reset tile
            if (cur_energy == 0) {
                continue;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    char cell = classroom[nr][nc];
                    
                    int next_energy = (cell == 'R') ? energy : (cur_energy - 1);
                    int next_mask = mask;
                    
                    if (cell == 'L') {
                        next_mask |= (1 << litter_map[{nr, nc}]);
                    }
                    
                    if (next_energy > max_energy[nr][nc][next_mask]) {
                        max_energy[nr][nc][next_mask] = next_energy;
                        q.push({nr, nc, next_mask, next_energy, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};