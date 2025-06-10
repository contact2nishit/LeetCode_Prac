class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int i = 0;
        int j = heights.size() - 1;
        while (i < j) {
            int min = (heights[i] < heights[j]) ? heights[i] : heights[j];
            if (((j-i) * min) > maxArea) maxArea = (j-i)*min;
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};