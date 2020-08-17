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
    // 找到二叉树最后一层最左的节点
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* cur = que.front();
            root = cur;
            que.pop();
            if(cur -> right != NULL) {
                que.push(cur -> right);
            }
            if(cur -> left != NULL) {
                que.push(cur -> left);
            }
        }
        return root -> val;
    }
};