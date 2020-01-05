/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 16:18:08
 */
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
    int dfs(TreeNode* root, int val, int& ans) {
        if(root == NULL) return 0;
        if(root -> val != val) {
            dfs(root, root -> val, ans);
            return 0;
        }
        else {
            int left = dfs(root -> left, val, ans);
            int right = dfs(root -> right, val, ans);
            ans = max(ans,1 + left + right);
            return 1 + max(left, right);
        }
        
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        dfs(root, root -> val, ans);
        return ans - 1;
    }
};