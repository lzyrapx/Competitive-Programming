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
    // 输出移除了所有不包含 1 的子树的原二叉树。
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        TreeNode* left = pruneTree(root -> left);
        TreeNode* right = pruneTree(root -> right);
        if(left == NULL && right == NULL && root -> val == 0) {
            // ignore this node
            return NULL;
        }
        else {
            root -> left = left;
            root -> right = right;
            return root;
        }
        
    }
};