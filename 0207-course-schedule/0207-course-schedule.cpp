class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto i: prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        unordered_set<int> visited;
        bool answer = true;
        for (int i = 0; i < numCourses; ++i) {
            answer = answer && dfs(i, adj, visited);
        }
        return answer;
    }

    bool dfs(int vertex, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(vertex);
        bool result = true;
        for (auto i: adj[vertex]) {
            if (visited.count(i)) return false;
            result = result && dfs(i, adj, visited);
        }
        visited.erase(vertex);
        adj[vertex].clear();
        return result;
    }
};