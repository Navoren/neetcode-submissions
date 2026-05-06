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
    
    int dfs(TreeNode* node, int mx) {
        if (!node) return 0;

        int good = 0;

        if (node->val >= mx)
            good = 1;

        mx = max(mx, node->val);

        return good +
               dfs(node->left, mx) +
               dfs(node->right, mx);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};