class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> vec1(26);
        vector<int> vec2(26);
        for (int i = 0; i < s1.size(); ++i) {
            vec1[s1[i] - 'a']++;
            vec2[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.size() - s1.size(); ++i) {
            if (vec1 == vec2) return true;
            vec2[s2[i + s1.size()] - 'a']++;
            vec2[s2[i] - 'a']--;
        }
        if (vec1 == vec2) return true;
        return false;
    }
};