class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int dr[] = {-1, +1, 0, 0}, dc[] = {0, 0, +1, -1}, nr, nc;
        for(int i = 0; i < 4; ++i) {
            nr = row + dr[i];
            nc = col + dc[i];
            // Wychodzimy poza zakres
            if(nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size()) continue;
            if(grid[nr][nc] == '0' || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            bfs(grid, visited, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int islands = 0;
        for(int row = 0; row < grid.size(); ++row) {
            for(int col = 0; col < grid[0].size(); ++col) {
                if(grid[row][col] == '0' || visited[row][col]) continue;
                visited[row][col] = true;
                bfs(grid, visited, row, col);
                islands++;
            }
        }
        return islands;
    }
};
