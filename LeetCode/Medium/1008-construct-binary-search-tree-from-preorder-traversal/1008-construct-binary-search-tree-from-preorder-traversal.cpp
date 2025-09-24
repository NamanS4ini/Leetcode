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
    int index;
    TreeNode* bstMaker(vector<int>& preorder,  int mini, int maxi) {
        if(index >= preorder.size())
            return NULL;
        if(preorder[index] > mini && preorder[index] < maxi){
            TreeNode* root = new TreeNode(preorder[index]);
            index++;
            root -> left = bstMaker(preorder, mini, root->val);
            root -> right = bstMaker(preorder, root->val, maxi);
            return root;
        }
        return NULL;
        
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstMaker(preorder, INT_MIN, INT_MAX);
    }
};