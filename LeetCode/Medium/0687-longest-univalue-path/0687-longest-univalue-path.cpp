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
    int res = 0;
    int diameter(TreeNode* root, int val){
        if(!root)
            return 0;
        int left = diameter(root ->left, root -> val);
        int right = diameter(root ->right, root -> val);
        res = max(res, left + right);
        if(root -> val == val){
            return max(left, right) + 1;
        }
        return 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        diameter(root, root -> val);
        return res;
    }
};