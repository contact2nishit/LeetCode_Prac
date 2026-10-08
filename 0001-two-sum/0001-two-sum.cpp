class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int search = target - nums[i];
            if (map.count(search) && i != map[search]) {
                result.push_back(i);
                result.push_back(map[search]);
                break;
            }
        }
        return result;
    }
};