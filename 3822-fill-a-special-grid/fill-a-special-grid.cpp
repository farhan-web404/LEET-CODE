class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int m = 1 << n;
        vector<vector<int>> ans(m, vector<int>(m));

        function<void(int,int,int,int)> solve = [&](int x, int y, int sz, int val) {
            if (sz == 1) {
                ans[x][y] = val;
                return;
            }

            int h = sz / 2;
            int add = h * h;

            solve(x, y + h, h, val);
            solve(x + h, y + h, h, val + add);
            solve(x + h, y, h, val + 2 * add);
            solve(x, y, h, val + 3 * add);
        };

        solve(0, 0, m, 0);
        return ans;
    }
};