class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector<int> subset;
        dfs(result, nums, subset, 1);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& subset, int i) {
        if (i > nums.size()) {
            result.push_back(subset);
            return;
        }
        dfs(result, nums, subset, i+1);
        subset.push_back(nums[i-1]);
        dfs(result, nums, subset, i+1);
        subset.pop_back();
    }   
};