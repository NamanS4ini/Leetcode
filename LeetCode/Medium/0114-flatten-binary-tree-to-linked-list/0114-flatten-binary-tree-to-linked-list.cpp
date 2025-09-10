class Solution {
    void preorder(TreeNode* root, queue<TreeNode*>&  q){
        if(!root)
            return;
        q.push(root);
        preorder(root -> left, q);
        preorder(root -> right, q);
    }
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        queue<TreeNode*> q;
        preorder(root, q);
        q.pop();
        while(q.size()){
            TreeNode* curr = q.front();
            q.pop();
            root -> left = NULL;
            root -> right = curr;
            root = curr;
        }
    }
};