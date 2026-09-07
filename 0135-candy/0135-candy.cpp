class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> candies(ratings.size(), 0);
        candies[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            } else {
                candies[i] = 1;
            }
        }
        for (int j = ratings.size() - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j+1]) candies[j] = max(candies[j], candies[j+1] + 1);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// [1, 2, 3, 1, 1] [2,2,1]