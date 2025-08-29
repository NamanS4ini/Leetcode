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
    bool sum(TreeNode* root, int currSum, int targetSum){
        if(!root)
            return false;

        currSum += root -> val;

        if(!root -> left && !root -> right){
            if(currSum == targetSum)
                return true;
            return false;
        }
        
        return sum(root ->left, currSum, targetSum) || sum(root-> right, currSum, targetSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sum(root, 0, targetSum);
    }
};