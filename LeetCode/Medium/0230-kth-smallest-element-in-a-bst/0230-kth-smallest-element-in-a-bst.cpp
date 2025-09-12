class Solution {
    int res;
    void solve(TreeNode* root, int& count, int k){
        if(!root){
            return;
        }
        solve(root -> left, count, k);
        count++;
        if(count == k){
            res = root -> val;
            return;
        }
        solve(root -> right, count, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        solve(root, cnt, k);
        return res;
    }
};