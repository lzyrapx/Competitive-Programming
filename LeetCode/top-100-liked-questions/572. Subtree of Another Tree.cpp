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
    bool dfs(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL) return true;
        if(s == NULL && t != NULL) return false;
        if(s != NULL && t == NULL) return false;
        if(s -> val == t -> val) return dfs(s -> left, t -> left) && dfs(s ->right, t -> right);
        else return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) return true;
        if(s == NULL && t != NULL) return false;
        if(s != NULL && t == NULL) return false;
        if(dfs(s,t)) return true;
        return isSubtree(s -> left, t) || isSubtree(s -> right, t);
    }
};