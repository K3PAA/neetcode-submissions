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
  
    int traversal(TreeNode *root, int maxVal) {
        if(!root) return 0;
        int left = traversal(root->left, max(maxVal, root->val));
        int right = traversal(root->right, max(maxVal, root->val));
        if(root->val >= maxVal) return left + right + 1;
        return left + right;
    }

    int goodNodes(TreeNode* root) {
        return traversal(root, -101);
    }
};
