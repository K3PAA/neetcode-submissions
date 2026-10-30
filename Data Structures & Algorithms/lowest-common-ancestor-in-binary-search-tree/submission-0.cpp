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
    int traversal(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** solution) {
        if(!root) return 0;
        int left = traversal(root->left, p, q, solution);
        int right = traversal(root->right, p, q, solution);
        int sum = left + right;
        if(sum == 2 && *solution == nullptr) *solution = root;
        else if(root == p || root == q) {
            if(sum == 1) *solution = root;
            sum++;
        }
        return sum;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* solution = nullptr;
        traversal(root, p, q, &solution);
        return solution;
    }
};
