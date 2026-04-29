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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;

        getPath(root, p, pathP);
        getPath(root, q, pathQ);

        int i = 0;
        TreeNode* ans = nullptr;

        while (i < pathP.size() && i < pathQ.size()) {
            if (pathP[i] == pathQ[i]) {
                ans = pathP[i];
            } else {
                break;
            }
            i++;
        }

        return ans;
    }

    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr) return false;

        path.push_back(root);

        if (root == target) return true;

        if (getPath(root->left, target, path) || 
            getPath(root->right, target, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
};
