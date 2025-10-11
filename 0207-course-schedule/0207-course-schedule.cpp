class Solution {

unordered_map<int, vector<int>> edges;
unordered_set<int> visiting;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++i) {
            edges[i] = {};
        }
        for (auto i: prerequisites) {
            edges[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }
    bool dfs(int vertex) {
        if (visiting.count(vertex)) return false;
        if (edges[vertex].empty()) return true;

        visiting.insert(vertex);
        for (int next: edges[vertex]) {
            if (!dfs(next)) {
                return false;
            }
        }
        visiting.erase(vertex);
        edges[vertex].clear();
        return true;
    }
};
