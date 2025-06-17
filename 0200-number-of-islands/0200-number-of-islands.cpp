class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0') return;
        else {grid[i][j] = '0';}
        if (i != 0) {
            DFS(i-1, j, grid);
        }
        if (j != 0) {
            DFS(i, j-1, grid);
        }
        if (i != grid.size() - 1) {
            DFS(i+1, j, grid);
        }
        if (j != grid[0].size() - 1) {
            DFS(i, j+1, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int num_Islands = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    num_Islands++;
                    DFS(i, j, grid);
                }
            }
        }
        return num_Islands;
    }
};