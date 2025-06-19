class Solution {
public:
    bool compMap(unordered_map<char, int>& tmap, unordered_map<char, int>& smap) {
        for (auto& i: tmap) {
            if (smap[i.first] < i.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int need = 0;
        if (s.size() < t.size() || s.size() == 0) return "";
        unordered_map<char, int> mapt;
        for (int i = 0; i < t.size(); ++i) {
            ++mapt[t[i]];
            ++need;
        }
        unordered_map<char, int> maps;
        int l = 0;
        int have = 0;
        string res = "";
        for (int r = 0; r < s.size(); ++r) {
            ++have;
            ++maps[s[r]];
            //res += s[r];
            while (have >= need && compMap(mapt, maps)) {
                --maps[s[l]];
                ++l;
                --have;
                //res = s.substr(l, r - l + 1);
            }
            if (l != 0 && (res.size() > s.substr(l-1, r-l+2).size() || res.size() == 0)) {
                res = s.substr(l-1, r -l + 2);
            }
        }
        return res;
    }
};