class Solution {
public:
int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp.at(0) = 0;
        for (int i = 0; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins.at(j) >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coins.at(j)]);
                }
            }
        }
        if (dp.at(amount) < amount+1) return dp.at(amount);
        else return -1;
    }
};