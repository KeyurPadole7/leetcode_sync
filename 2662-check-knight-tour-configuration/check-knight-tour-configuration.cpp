class Solution {
public:
    const vector<pair<int, int>> moves = {
        {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2},
        {2, -1}, {2, 1}, {1, -2}, {1, 2}
    };

    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    bool val(vector<vector<int>>& grid, int row, int coln, int idx) {
        int n = grid.size();
        if (grid[row][coln] != idx) return false;
        if (idx == n * n - 1) return true;

        for (const auto& [dr, dc] : moves) {
            int nr = row + dr;
            int nc = coln + dc;
            if (isValid(nr, nc, n) && grid[nr][nc] == idx + 1) {
                return val(grid, nr, nc, idx + 1);
            }
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        return val(grid, 0, 0, 0);
    }
};