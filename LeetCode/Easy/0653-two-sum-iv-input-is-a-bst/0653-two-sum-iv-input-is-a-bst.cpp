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
    void inorder(TreeNode* root, vector<int>& ino){
        if(!root)
            return;
        inorder(root->left, ino);
        ino.push_back(root -> val);
        inorder(root->right, ino);

    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ino;
        inorder(root, ino);
        int left = 0;
        int right = ino.size() - 1;
        while(left < right){
            int sum = ino[left] + ino[right];
            if(sum == k)
                return true;
            else if(sum < k)
                left++;
            else
                right--;
        }
        return false;
    }
};