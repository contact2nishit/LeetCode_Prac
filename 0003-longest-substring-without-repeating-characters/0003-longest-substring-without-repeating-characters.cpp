#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int length = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (map.count(s[i]) && map[s[i]] >= start) {
                start = map[s[i]] + 1;
            }
            map[s[i]] = i;
            length = max(length, i - start + 1);
        }
        return length;
    }
};