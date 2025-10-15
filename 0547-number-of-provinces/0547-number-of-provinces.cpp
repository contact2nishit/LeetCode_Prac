class Solution {
public:
    void dfs(int vertex, unordered_set<int>& visited, vector<vector<int>>& isConnected) {
        for (int j = 1; j < isConnected[0].size() + 1; ++j) {
            if (vertex == j) continue;
            if (isConnected[vertex - 1][j - 1] == 1 && !visited.count(j)) {
                visited.insert(j);
                dfs(j, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;
        //visited.insert(1);
        int count = 0;
        for (int i = 1; i < isConnected.size() + 1; ++i) {
            if (!visited.count(i)) {
                //cout << "i" << endl;
                visited.insert(i);
                dfs(i, visited, isConnected);
                ++count;
            }
        }
        return count;
    }
};