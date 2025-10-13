class Solution {
unordered_map<int, vector<pair<int, int>>> map;
unordered_map<int, int> visited;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto i : times) {
            map[i[0]].push_back(pair{i[2], i[1]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        q.push(pair{0,k});
        visited[k] = 0;
        while (!q.empty()) {
            auto [dist, node] = q.top();
            q.pop();
            if (dist > visited[node]) continue;
            for (auto i: map[node]) {
                if (!visited.count(i.second) || (visited[i.second] > dist + i.first)) {
                    visited[i.second] = dist + i.first;
                    q.push(pair{dist + i.first, i.second});
                }
            }
        }
        if (visited.size() != n) return -1;
        int maxTime = 0;
        for (auto i : visited) {
            maxTime = max(maxTime, i.second);
        }
        return maxTime;
    }
};