class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; ++i) {
            int counter = 0;
            int k = i;
            while (k != 0) {
                if (k % 2 == 1) ++counter;
                k /= 2;
            }
            result.push_back(counter);
        }
        return result;
    }
};