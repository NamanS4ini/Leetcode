/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void preorder(string& s, TreeNode* root){
        if(!root){
            s.append("N");
            return;
        }
        s.append(to_string(root->val));
        s.append("L");
        preorder(s,root->left);
        s.append("R");
        preorder(s,root->right);

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preorder(s,root); 
        // cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        if(data[0] == 'N'){
            data.erase(data.begin());
            return NULL;
        }
        string num = "";
        while(data[0] != 'L' && data[0] != 'R' && data[0] != 'N'){
            if(data[0] == '-'){
                num.append("-");
            }
            else
                num.append(to_string((data[0] - '0')));
            data.erase(data.begin());
        }
        if(!num.length())
            return nullptr;
        TreeNode* root = new TreeNode(stoi(num));
        if(data[0] == 'L'){
            data.erase(data.begin());
            root -> left = deserialize(data);
        }
        if(data[0] == 'R'){
            data.erase(data.begin());
            root -> right = deserialize(data);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));