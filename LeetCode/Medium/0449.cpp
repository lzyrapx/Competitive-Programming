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
public:
    // 序列化和反序列化
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "#";
        }
        return to_string(root -> val) + " " + serialize(root -> left) + " " + serialize(root -> right);
    }
    TreeNode* rebuildTree(stringstream& data) {
        string str;
        data >> str;
        if(str == "#") {
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(str));
        node->left = rebuildTree(data);
        node->right = rebuildTree(data);
        return node;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rebuildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));