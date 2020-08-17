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
    //  给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root == NULL) {
            return NULL;
        }
        if(d == 1) {
            TreeNode* node = new TreeNode(v);
            node -> left = root;
            return node;
        }
        queue<TreeNode*>que;
        que.push(root);
        
        int level = 2;
        
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                TreeNode* cur = que.front(); // 第 d - 1 层
                que.pop();
                
                if(d == level) {
                    // 当前层指向新加的层，先处理左边，再处理右边
                    TreeNode* tmp = cur -> left;
                    cur -> left = new TreeNode(v);
                    cur -> left -> left = tmp;
                    
                    tmp = cur -> right;
                    cur -> right = new TreeNode(v);
                    cur -> right -> right = tmp;
                }
                
                if(cur -> left != NULL) {
                    que.push(cur -> left);
                }
                if(cur -> right != NULL) {
                    que.push(cur -> right);
                }
            }
            level++;
        }
        return root;
    }
};