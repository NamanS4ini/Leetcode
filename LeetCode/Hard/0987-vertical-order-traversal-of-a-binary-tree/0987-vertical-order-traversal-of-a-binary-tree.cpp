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
    void preorder(TreeNode* root, int row, int col, vector<pair<pair<int,int>, int>>& ans){
        if(!root)
            return;
        ans.push_back({{col, row}, root -> val});
        preorder(root -> left, row + 1, col - 1, ans);
        preorder(root -> right, row + 1, col + 1, ans);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<pair<int,int>, int>> ans;
        preorder(root, 0, 0, ans);
        sort(ans.begin(), ans.end());
        int size = abs(ans[ans.size() - 1].first.first) + abs(ans[0].first.first) + 1;
        vector<vector<int>> res(size);
        int curr = ans[0].first.first;
        int min = abs(ans[0].first.first);
        for(auto m: ans){
            res[m.first.first + min].push_back(m.second);
        }
        return res;
    }
};