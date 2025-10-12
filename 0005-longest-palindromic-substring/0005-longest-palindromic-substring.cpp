class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1) return s;
        string result;
        result += s.at(0);
        for (int i = 1; i < s.size() -1; ++i) {
            int l = i -1;
            int r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (s.substr(l, r -l+1).size() > result.size()) result = s.substr(l, r-l+1);
                --l;
                ++r;
            }
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            int initial = i;
            int j = i+1;
            while (i >= 0 && j < s.size() && s[i] == s[j]) {
                if (s.substr(i, j -i+1).size() > result.size()) result = s.substr(i, j-i+1);
                ++j;
                --i;
            }
            i = initial;
        }
        return result;
    }
};