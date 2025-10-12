class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        vector<int> dp(s.size());
        dp[0] = 1;
        if (s[1] == '0') {
            if (s[0] != '1' && s[0] != '2') return 0;
            else dp[1] = 1;
        } else {
            dp[1] = (stoi(s.substr(0, 2)) <= 26) ? 2 : 1;
        }
        //cout << dp[1];
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == '0' && (s[i-1] != '1' && s[i-1] != '2')) return 0;
            if (s[i] != '0') dp[i] += dp[i-1];
            if (s[i-1] != '0' && stoi(s.substr(i-1,2)) <= 26) dp[i] += dp[i-2];
        }
        return dp[dp.size() -1];
    }
};