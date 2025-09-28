class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0) return 0;
        int area = 1;
        grid[i][j] = 0;
        if (i != 0) {
            area += bfs(grid, i-1, j);
        }
        if (i != grid.size() - 1) {
            area += bfs(grid, i+1, j);
        }
        if (j != 0) {
            area += bfs(grid, i, j-1);
        }
        if (j != grid[0].size() - 1) {
            area += bfs(grid, i, j+1);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                maxArea = max(maxArea, bfs(grid, i, j));
            }
        }
        return maxArea;
    }
};