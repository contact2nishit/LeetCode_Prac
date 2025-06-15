class Solution {
public:
    int trap(vector<int>& height) {
        int trappedArea = 0;
        int i = 1;
        int j = height.size() - 2;
        int maxL = height.at(0);
        int maxR = height.at(height.size() - 1);
        while (i <= j) {
            if (maxL > maxR) {
                if (height[j] > maxR) {
                    maxR = height[j];
                } else {
                    trappedArea += maxR - height[j];
                }
                j--;
            } else {
                if (height[i] > maxL) {
                    maxL = height[i];
                } else {
                    trappedArea += maxL - height[i];
                }
                i++;
            }
        }
        return trappedArea;
    }
};