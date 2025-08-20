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
    pair <int, int> diameter(TreeNode* root){
        if(!root)
            return {0,0};
        pair<int, int> h1 = diameter(root -> left);
        pair<int, int> h2 = diameter(root -> right);
        int h3 = h1.second + h2.second + 1;
        return {max(h1.first, max(h2.first, h3)), max(h1.second, h2.second) + 1};

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return max(diameter(root).first, diameter(root).second) - 1;
    }
};