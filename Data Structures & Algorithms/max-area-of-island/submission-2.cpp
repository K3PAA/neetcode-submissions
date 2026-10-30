class Solution {
public:
public:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int dr[] = {-1, +1, 0, 0}, dc[] = {0, 0, +1, -1}, nr, nc;
        int count = 0;
        for(int i = 0; i < 4; ++i) {
            nr = row + dr[i];
            nc = col + dc[i];
            // Wychodzimy poza zakres
            if(nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size()) continue;
            if(grid[nr][nc] == 0 || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            count += (bfs(grid, visited, nr, nc) + 1);
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int maxVal = 0;
        for(int row = 0; row < grid.size(); ++row) {
            for(int col = 0; col < grid[0].size(); ++col) {
                if(grid[row][col] == 0 || visited[row][col]) continue;
                visited[row][col] = true;
                maxVal = max(bfs(grid, visited, row, col) + 1, maxVal);
            }
        }
        return maxVal;
    }
};
