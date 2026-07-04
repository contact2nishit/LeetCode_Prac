class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] > limit) {
                --r;
                ++res;
            } else {
                --r;
                ++l;
                ++res;
            }
        }
        return res;
    }
};