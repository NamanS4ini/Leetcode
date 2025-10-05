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
    void makeBST(TreeNode* root){
        if(!root)
            return;

        makeBST(root -> right);
        root -> val += sum;
        sum = root -> val;
        makeBST(root -> left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        makeBST(root);
        return root;
    }
};