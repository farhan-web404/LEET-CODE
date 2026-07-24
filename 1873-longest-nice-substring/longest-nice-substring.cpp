class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            vector<int> low(26, 0), up(26, 0);

            for (int j = i; j < n; j++) {
                if (islower(s[j]))
                    low[s[j] - 'a'] = 1;
                else
                    up[s[j] - 'A'] = 1;

                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (low[k] != up[k]) {
                        if (low[k] || up[k]) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }
        }

        return ans;
    }
};