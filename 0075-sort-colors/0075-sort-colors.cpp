class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (const auto& i : nums) {
            ++freqMap[i];
        }
        nums.clear();
        nums.insert(nums.end(), freqMap[0], 0);
        nums.insert(nums.end(), freqMap[1], 1);
        nums.insert(nums.end(), freqMap[2], 2);
    }
};