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
    int res = INT_MIN;
    int sum(TreeNode* root){
        if(!root)
            return 0;
        int left = sum(root -> left);
        int right = sum(root -> right);
        left = left < 0 ? 0 : left;
        right = right < 0 ? 0 : right;
        res = max(res, left + right + root ->val);
        return max(left, right) + root ->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int val = sum(root);
        return max(res, val);
    }
};