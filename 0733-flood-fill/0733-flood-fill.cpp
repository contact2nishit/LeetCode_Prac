class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int current, int color) {
        if (image[sr][sc] != current) return;
        else image[sr][sc] = color;
        if(sr != 0) dfs(image, sr-1, sc, current, color);
        if(sr != image.size() -1) dfs(image, sr+1, sc, current, color);
        if(sc != 0) dfs(image, sr, sc-1, current, color);
        if(sc != image[0].size() -1) dfs(image, sr, sc+1, current, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};