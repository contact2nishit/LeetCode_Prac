#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> num_to_index;
           for (int i = 0; i < nums.size(); ++i) {
               int complement = target - nums.at(i);
               if (num_to_index.count(complement)) {
                return vector<int> {num_to_index[complement], i};
               }
               num_to_index[nums[i]] = i;
           }
        return vector<int> {};
    }
};