class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = build(nums, l, m - 1);
        root->right = build(nums, m + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};