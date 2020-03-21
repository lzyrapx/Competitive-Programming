/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-15 01:50:56
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
    int ans = 0;
    void dfs(TreeNode* root, int direction, int depth) {
        if(root == NULL) {
            return;
        }
        ans = max(ans, depth);
        if(direction == 0) { // left
            dfs(root -> right, direction ^ 1, depth + 1);
            dfs(root -> left, direction ^ 1, 0);
        }
        else { // right
            dfs(root -> left, direction ^ 1, depth + 1);
            dfs(root -> right, direction ^ 1, 0);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) {
            return 0;
        }
        dfs(root, 0, 0);
        dfs(root, 1, 0);
        return ans;
    }
};