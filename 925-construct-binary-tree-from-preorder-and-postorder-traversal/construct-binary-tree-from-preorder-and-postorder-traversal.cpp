/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> pos;

    TreeNode* build(vector<int>& pre, vector<int>& post, int &i, int l, int r) {
        if (i >= pre.size() || l > r) return NULL;

        TreeNode* root = new TreeNode(pre[i++]);
        if (l == r) return root;

        int idx = pos[pre[i]];
        root->left = build(pre, post, i, l, idx);
        root->right = build(pre, post, i, idx + 1, r - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++)
            pos[postorder[i]] = i;
        int i = 0;
        return build(preorder, postorder, i, 0, postorder.size() - 1);
    }
};