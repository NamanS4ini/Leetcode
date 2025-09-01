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
    int good = 0;
    void solve(TreeNode* root, vector<int>& seen){
        if(!root)
            return;
        for(int n: seen){
            if(n > root -> val){
                good--;
                break;
            }
        }
        good++;
        seen.push_back(root->val);
        solve(root->left, seen);
        solve(root->right, seen);
        seen.pop_back();
    }
public:
    int goodNodes(TreeNode* root) {
        vector<int> seen;
        solve(root, seen);
        return good;

    }
};