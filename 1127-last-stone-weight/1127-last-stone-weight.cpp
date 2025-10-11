class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1) {
            int stone1 = q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();
            int new_stone = abs(stone1 - stone2);
            if (new_stone != 0) q.push(new_stone);
        }
        if(q.size() == 1) return q.top();
        else return 0;
    }
};