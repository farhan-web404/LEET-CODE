class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char,int>> v;
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            v.push_back({t[i], j - i});
            i = j;
        }

        int ans = 0;
        for (char c : s) ans += c == '1';

        int cur = ans;

        for (int i = 1; i + 1 < v.size(); i++) {
            if (v[i].first == '1' && v[i - 1].first == '0' && v[i + 1].first == '0') {
                int gain = v[i - 1].second + v[i + 1].second;
                cur = max(cur, ans - v[i].second + gain + v[i].second);
            }
        }

        return cur;
    }
};