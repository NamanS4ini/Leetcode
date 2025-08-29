/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int res = 0;

    void preOrder(TreeNode* root, int targetSum){
        if(!root)
            return;
        sum(root, 0, targetSum);
        preOrder(root->left, targetSum);
        preOrder(root->right, targetSum);
    }
    void sum(TreeNode* root, long long currSum, int targetSum) {
        if (!root)
            return;
        currSum += root -> val;

        if (currSum == targetSum)
            res++;

        sum(root->left, currSum, targetSum);
        sum(root->right, currSum, targetSum);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        preOrder(root, targetSum);
        return res;
    }
};