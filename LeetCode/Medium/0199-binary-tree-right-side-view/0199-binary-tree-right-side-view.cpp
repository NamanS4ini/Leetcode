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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> lot;
        vector<int> out;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                lot.push_back(out);
                out = {};
                if(q.size()){
                    q.push(NULL);
                }
            }
            else{
                out.push_back(temp -> val);
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
            }
        }
        vector<int> ans;
        for(vector<int> l: lot){
            ans.push_back(l[l.size() - 1]);
        }
        return ans;
    }
};