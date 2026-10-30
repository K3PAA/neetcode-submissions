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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> solution;
        if(root == nullptr) return solution;
        
        queue<TreeNode*> kolejka;
        kolejka.push(root);
        kolejka.push(nullptr);

        int doDodania;
        while(kolejka.size() != 1) {
            TreeNode *node = kolejka.front();
            kolejka.pop();
            if(node) {
                doDodania = node->val;
                if(node->left) kolejka.push(node->left);
                if(node->right) kolejka.push(node->right);
            } else {
                solution.push_back(doDodania);
                kolejka.push(nullptr);
            }
        }
        solution.push_back(doDodania);

        return solution;
    }
};
