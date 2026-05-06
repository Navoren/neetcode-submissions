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
    int pathSum(TreeNode* node, int &maxi){
        if(node == nullptr) return 0;

        int lSum = max(0, pathSum(node->left, maxi));
        int rSum = max(0, pathSum(node->right, maxi));
        maxi = max(maxi, node->val + lSum + rSum);

        return node->val + max(lSum, rSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        pathSum(root, maxi);
        return maxi;
    }
};