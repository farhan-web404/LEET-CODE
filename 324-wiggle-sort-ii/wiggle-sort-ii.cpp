class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());

        int n = nums.size();
        int j = (n - 1) / 2;
        int k = n - 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                nums[i] = v[j--];
            else
                nums[i] = v[k--];
        }
    }
};