class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> v;
        vector<vector<int>> pre(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                v.push_back(pre[i][j]);
            }
        }

        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
        return v[k - 1];
    }
};