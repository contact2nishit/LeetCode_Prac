class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n+1);
        dp.at(1) = 1;
        dp.at(2) = 2;
        for (int i = 3; i <= n; ++i) {
            dp.at(i) = dp.at(i-1) + dp.at(i-2);
        }
        return dp.at(n);
    }
};