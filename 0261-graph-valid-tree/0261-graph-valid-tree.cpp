class Solution {
unordered_map <int, vector<int>> map;
unordered_set <int> visited;
unordered_set <int> visiting;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i) {
            map[i] = {};
        }
        for (auto i: edges) {
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
        }
        bool hasCycle = dfs(0, -1);
        return (!hasCycle && (visited.size() == n));
    }

    bool dfs(int vertex, int parent) {
        if (visiting.count(vertex)) return true;
        //if (map[vertex].empty()) return false;
        visiting.insert(vertex);
        bool hasCycle = false;
        for (auto i: map[vertex]) {
            if (i == parent) continue;
            hasCycle = hasCycle || dfs(i, vertex);
        }
        visiting.erase(vertex);
        visited.insert(vertex);
        map[vertex].clear();
        return hasCycle;
    }
};
