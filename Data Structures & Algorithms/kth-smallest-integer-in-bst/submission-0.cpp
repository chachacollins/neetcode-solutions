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
    void walk(TreeNode* node, vector<int> &vals) {
        if(!node) return;
        walk(node->left, vals);
        vals.push_back(node->val);
        walk(node->right, vals);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> val;
        walk(root, val);
        return val[max(0, k-1)];
    }
};
