class Solution {
public:
    TreeNode* build(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie) {
        if (ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(pre[ps]);

        int k = is;
        while (in[k] != pre[ps]) k++;

        int left = k - is;

        root->left = build(pre, ps + 1, ps + left, in, is, k - 1);
        root->right = build(pre, ps + left + 1, pe, in, k + 1, ie);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};