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
    int traverse(TreeNode *node, int level) {
        if(!node) return level;
        return max(traverse(node->left, level+1),
         traverse(node->right,level+1));
    }
    int maxDepth(TreeNode* root) {
        return traverse(root,0);
    }
};
