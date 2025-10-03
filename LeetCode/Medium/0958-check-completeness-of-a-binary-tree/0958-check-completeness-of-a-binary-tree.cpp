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
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* temp = q.front();
            q.pop();
            if (!temp && q.size()) {
                while (!q.empty()) {
                    if (q.front())
                        return false;
                    q.pop();
                }
            }
            if (temp) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};