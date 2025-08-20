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
        pair<int, int> pLeft = diameter(root -> left);
        pair<int, int> pRight = diameter(root -> right);
        int hLeft = pLeft.first;
        int hRight = pRight.first;
        int hBoth = pLeft.second + pRight.second + 1;
        return {max(hLeft, max(hRight, hBoth)), max(pLeft.second, pRight.second) + 1};

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return max(diameter(root).first, diameter(root).second) - 1;
    }
};