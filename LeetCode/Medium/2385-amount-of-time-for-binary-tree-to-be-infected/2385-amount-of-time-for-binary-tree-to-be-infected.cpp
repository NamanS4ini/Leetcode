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
    void preorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;
        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;
        preorder(root->left, parent);
        preorder(root->right, parent);
    }
    TreeNode* findNode(TreeNode* root, int start, TreeNode* node) {
        if (!root)
            return nullptr;
        if (root->val == start) {
            return root;
        }
        TreeNode* left = findNode(root->left, start, node);
        TreeNode* right = findNode(root->right, start, node);
        if (!left)
            return right;
        return left;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        preorder(root, parent);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        TreeNode* node = findNode(root, start, node);
        q.push(node);
        visited[node] = true;
        int time = 0;

        while (q.size()) {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    flag = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    flag = true;
                    q.push(curr->right);
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    flag = true;
                    q.push(parent[curr]);
                }
            }
            if (flag)
                time++;
        }
        return time;
    }
};