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
    void sum(TreeNode* root,vector<int> out, vector<vector<int>>& ans, int currSum, int targetSum){
        if(!root)
            return;

        currSum += root -> val;
         out.push_back(root->val);

        if(!root -> left && !root -> right){
            if(currSum == targetSum){
                ans.push_back(out);
                }
                return;
        }
        sum(root ->left, out, ans, currSum, targetSum);
        sum(root-> right, out, ans, currSum, targetSum);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> out;
        vector<vector<int>> ans;
        sum(root, out, ans, 0, targetSum);
        return ans; 
    }
};