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
    int res;
    int diameter(TreeNode* root){
        if(!root)
            return 0;
        int h1 = diameter(root->left);
        int h2 = diameter(root->right);
        res = max(res, h1 + h2);
        return max(h1, h2) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        diameter(root);
        return res;
    }
};