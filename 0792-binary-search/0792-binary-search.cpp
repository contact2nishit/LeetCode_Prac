class Solution {
public:
    int Binary(vector<int>& nums, int target, int left, int right) {
        if(left == right) return -1;
        int mid = left + (right - left)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) return Binary(nums, target, left, mid);
        else { return Binary(nums, target, mid+1, right);}
    }
    int search(vector<int>& nums, int target) {
        return Binary(nums, target, 0, nums.size());
    }
};