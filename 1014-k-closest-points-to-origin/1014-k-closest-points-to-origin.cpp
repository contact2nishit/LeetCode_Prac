class comparePoints {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            if ((a[0]*a[0]) + (a[1]*a[1]) < (b[0]*b[0]) + (b[1]*b[1])) {
                return true;
            } else return false;
        }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comparePoints> q;
        for (const auto& point : points) {
            q.push({point[0], point[1]});
            if (q.size() > k) q.pop();
        }
        vector<vector<int>> result;
        while (!q.empty()) {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};