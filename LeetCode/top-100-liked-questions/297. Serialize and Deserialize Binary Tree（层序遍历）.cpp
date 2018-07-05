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

    // 序列化可以是层序遍历，也可以是先序遍历
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(root == NULL) return ans;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *cur = que.front(); 
            que.pop();
            if (cur != NULL) 
            {
                ans = ans + to_string(cur -> val) + " ";
                que.push(cur -> left);
                que.push(cur -> right);
            } 
            else {
                ans += "# ";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        istringstream in(data);
        string val;
        in >> val;
        
        TreeNode *ans = new TreeNode(stoi(val));
        TreeNode* root = ans;
        
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) 
        {
            TreeNode *cur = que.front(); 
            que.pop();
            
            if (!(in >> val)) break;
            if (val != "#") 
            {
                root = new TreeNode(stoi(val));
                que.push(root);
                cur -> left = root;
            }
            
            if (!(in >> val)) break;
            if (val != "#") 
            {
                root = new TreeNode(stoi(val));
                que.push(root);
                cur -> right = root;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));