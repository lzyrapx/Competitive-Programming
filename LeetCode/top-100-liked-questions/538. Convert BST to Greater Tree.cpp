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
    int cur_sum = 0;
    void dfs(TreeNode* root) 
    {
        if(root == NULL) return;
        if(root ->right) dfs(root -> right);
        
        cur_sum += root -> val;
        root -> val = cur_sum;
        
        if(root -> left) dfs(root -> left);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};