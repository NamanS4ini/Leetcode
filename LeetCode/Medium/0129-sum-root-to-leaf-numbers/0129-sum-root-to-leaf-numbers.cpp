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
    int sum = 0;
    void preOrder(TreeNode* root, int num){
        if(!root)
            return;
        if(!root ->right && ! root->left){
            num *= 10;
            num+= root-> val;
            sum += num;
            return;
        }
        num *= 10;
        num+= root-> val;
        preOrder(root-> left, num);
        preOrder(root-> right, num);
    }
public:
    int sumNumbers(TreeNode* root) {
        preOrder(root, 0);
        return sum;
    }

};