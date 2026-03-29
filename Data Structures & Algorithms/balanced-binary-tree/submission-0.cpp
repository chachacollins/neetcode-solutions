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
    int walk(TreeNode *node, bool &bal) {
        if(!node) return 0;
        int left =  walk(node->left,bal);
        int right = walk(node->right, bal);
        int lr = abs(left - right);
        if(lr > 1) bal = false;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool bal = true;
        walk(root, bal);
        return bal;
    }
};
