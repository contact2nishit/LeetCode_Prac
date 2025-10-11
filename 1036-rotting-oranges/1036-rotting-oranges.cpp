class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        queue<pair<int, int>>q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) q.push(pair(i, j));
            }
        }
        while (!q.empty()) {
            vector<pair<int, int>> v;
            while(!q.empty()) {
                if (q.front().first != 0 && grid[q.front().first-1][q.front().second] == 1) {
                    grid[q.front().first-1][q.front().second] = 2; 
                    v.push_back(pair(q.front().first-1, q.front().second));
                }
                if (q.front().first != grid.size()-1 && grid[q.front().first+1][q.front().second] == 1) { 
                    grid[q.front().first+1][q.front().second] = 2;
                    v.push_back(pair(q.front().first+1, q.front().second));
                };
                if (q.front().second != 0 && grid[q.front().first][q.front().second-1] == 1){
                    grid[q.front().first][q.front().second-1] = 2;
                    v.push_back(pair(q.front().first, q.front().second-1));
                }
                if (q.front().second != grid[0].size() -1 && grid[q.front().first][q.front().second+1] == 1) {
                    grid[q.front().first][q.front().second+1] = 2;
                    v.push_back(pair(q.front().first, q.front().second+1));
                }                                                                             
                q.pop();
            }
            cout << endl;
            while(!v.empty()) {
                q.push(pair(v.front().first, v.front().second));
                v.erase(v.begin());
            }
            // for (auto i: v) {
            //     cout << "(" << i.first << "," << i.second << ")";
            // }
            ++count;
            //cout << count << endl;
        }
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) return -1;
        }
    }
    if(count == 0) return count;
    else return count - 1;
    }
};