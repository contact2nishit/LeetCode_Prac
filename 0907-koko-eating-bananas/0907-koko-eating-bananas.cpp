class Solution {
public:
    bool thisWorks(vector<int>& piles, int h, int k) {
        size_t sum = 0;
        for (const auto& i: piles) {
            sum += ceil(static_cast<double>(i)/k);
        }
        if (sum > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1;
        for (int i = 0; i < piles.size(); ++i) {
            right = max(piles[i], right);
        }
        int result = right;
        if (piles.size() == 1) return ceil(piles[0]/(static_cast<double>(h)));
        while (right >= left) {
            int k = left + ((right - left)/2);
            if (thisWorks(piles, h, k)) {
                right = k - 1;
                if (k < result) result = k;
            } else {
                left = k + 1;
            }
        }
        return result;
    }
};