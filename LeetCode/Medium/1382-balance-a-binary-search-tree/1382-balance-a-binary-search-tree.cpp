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
    void inorder(TreeNode* root, vector<TreeNode*>& nodes){
        if(!root)
            return;
        inorder(root -> left, nodes);
        nodes.push_back(root);
        inorder(root -> right, nodes);
    }
    TreeNode* makeBST(int start, int end, vector<TreeNode*>& nodes){
        if(start > end)
            return NULL;
        int mid = (start + end) / 2;
        nodes[mid] -> left = makeBST(start, mid - 1, nodes);
        nodes[mid] -> right = makeBST(mid + 1, end, nodes);
        return nodes[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return makeBST(0, nodes.size() - 1, nodes);        
    }
};