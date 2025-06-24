class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target, int left, int right) {
        if (left == right) return false;
        int mid = left + (right - left)/2;
        int to_check = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
        if ( to_check == target) return true;
        else if (to_check > target) return binarySearch(matrix, target, left, mid);
        else {
            return binarySearch(matrix, target, mid + 1, right);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix, target, 0, matrix.size()*matrix[0].size());
    }
};