class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0;
        unordered_map<char, int> map;
        int l = 0;
        int maxf = 0;
        for (int r = 0; r < s.size(); ++r) {
            map[s[r]]++;
            maxf = max(maxf, map[s[r]]);

            while ((r - l + 1) - maxf > k) {
                map[s[l]]--;
                l++;
            }
            length = max(length, r - l + 1);
        }
        return length;
    }
};