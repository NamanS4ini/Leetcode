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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size() || !inorder.size())
            return NULL;
        int curr = preorder[0];
        TreeNode* root = new TreeNode(curr);
        preorder.erase(preorder.begin());
        int idx = 0;
        for(int i = 0; i < inorder.size(); i++){
            int n = inorder[i];
            if(n == curr){
                idx = i;
                break;
            }
        }
        vector<int> left;
        for(int i = 0; i < idx; i++){
            left.push_back(inorder[i]);
        }
        vector<int> right;
        for(int i = idx+1; i< inorder.size(); i++){
            right.push_back(inorder[i]);
        }
        root -> left = buildTree(preorder, left);
        root -> right = buildTree(preorder, right);

        return root;

    }
};