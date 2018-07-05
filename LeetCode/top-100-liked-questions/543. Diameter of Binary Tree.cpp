/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxdepth = 0;
    int  dfs(TreeNode* root)
    {
        if(root == NULL) return 0;
        int leftdepth = dfs(root -> left);
        int rightdepth = dfs(root -> right);
        if(leftdepth + rightdepth >= maxdepth) maxdepth = leftdepth + rightdepth;
        return max(leftdepth + 1, rightdepth + 1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxdepth;
    }
};