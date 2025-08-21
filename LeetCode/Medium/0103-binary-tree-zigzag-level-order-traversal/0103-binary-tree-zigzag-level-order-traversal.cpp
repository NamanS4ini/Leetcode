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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> res;
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                count++;
                if(count % 2 == 0){
                    reverse(res.begin(), res.end());
                }
                        ans.push_back(res);
                    res = {};
                if(q.size())
                    q.push(NULL);
            }
            else{
                res.push_back(temp -> val);
                if(temp->left)
                    q.push(temp-> left);
                if(temp->right)
                    q.push(temp-> right);
            }
        }
        return ans;
    }
};