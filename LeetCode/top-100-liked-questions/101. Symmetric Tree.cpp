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
    bool dfs(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 != NULL && t2 == NULL) return false;
        if(t1 == NULL && t2 != NULL) return false;
        if(t1 -> val == t2 -> val){
            return dfs(t1 -> left, t2 -> right) && dfs(t1 -> right, t2 -> left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root -> left, root -> right);
    }
};