/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-05 22:18:42
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
    int sum = 0;
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        if(root -> left && root -> left -> left == NULL && root ->left -> right == NULL) {
            sum += root -> left -> val;
        }
        dfs(root -> left);
        dfs(root -> right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root);
        return sum;
    }
};