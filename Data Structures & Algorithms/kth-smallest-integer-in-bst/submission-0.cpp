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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        inOrder(root, order);
        return order[k-1];
    }

    void inOrder(TreeNode* node, vector<int> &order){
        if(node == nullptr){
            return;
        }

        inOrder(node->left, order);
        order.push_back(node->val);
        inOrder(node->right, order);
    }
};