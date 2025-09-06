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
    void lpreorder(TreeNode* root, vector<int>& v){
        if(!root){
            v.push_back(-1);
            return;
        }
        v.push_back(root->val);
        lpreorder(root -> left, v);
        lpreorder(root -> right, v);
    }
    void rpreorder(TreeNode* root, vector<int>& v){
        if(!root){
            v.push_back(-1);
            return;
        }
        v.push_back(root->val);
        rpreorder(root -> right, v);
        rpreorder(root -> left, v);
    }
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> left;
        vector<int> right;
        if(root -> left){
            lpreorder(root -> left, left);
        }
        if(root -> right){
            rpreorder(root -> right, right);
        }
        return left == right;
    }
};