class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size()-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; ++i) {
            dp[i] = max((nums[i] + dp[i-2]), dp[i-1]);
        }
        vector<int> dp2(nums.size()-1);
        dp2[0] = nums[nums.size() -1];
        dp2[1] = max(nums[nums.size() -1], nums[nums.size() -2]);
        for (int i = 2; i < nums.size() - 1; ++i) {
            dp2[i] = max((nums[nums.size() - i -1] + dp2[i-2]), dp2[i-1]);
        }
        return max(dp[dp.size() -1], dp2[dp2.size() -1]);
    }
};