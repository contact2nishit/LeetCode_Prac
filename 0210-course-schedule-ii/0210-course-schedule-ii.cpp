class Solution {
unordered_map <int, vector<int>> edges;
unordered_set <int> visiting;
vector<int> visited = {};
unordered_set<int> already_visited;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++i) {
            edges[i] = {};
        }
        for (auto i: prerequisites) {
            edges[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if(!dfs(i)) return {};
        }
        return visited;
    }

    bool dfs(int vertex) {
        if (visiting.count(vertex)) return false;
        visiting.insert(vertex);
        for (auto i: edges[vertex]) {
            if (!dfs(i)) return false;
        }
        if (!already_visited.count(vertex)) {
            visited.push_back(vertex);
        }
        visiting.erase(vertex);
        already_visited.insert(vertex);
        edges[vertex].clear();
        return true;
    }
};