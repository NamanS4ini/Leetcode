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
    bool res =  false;
    void solve(TreeNode* root, int targetSum, int curr){
        if(!root -> left && !root -> right){
            if(curr + root -> val == targetSum){
                res = true;
            }
            return;
        }
        if(root -> right)
            solve(root -> right, targetSum, curr + root -> val);
        if(root -> left)
            solve(root -> left, targetSum, curr + root -> val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        solve(root, targetSum, 0);
        return res;
    }
};