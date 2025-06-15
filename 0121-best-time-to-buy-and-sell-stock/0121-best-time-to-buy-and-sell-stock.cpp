class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int min = INT_MAX;
        int max_profit = 0;
        while (i < prices.size()) {
            if (prices[i] < min) {
                min = prices[i];
            }
            if (prices[i] - min > max_profit) max_profit = prices[i] - min;
            i++;
        }
        return max_profit;
    }
};