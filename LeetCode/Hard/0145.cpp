/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-25 20:26:57
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
    // 后序遍历： dfs or 用两个栈
    void dfs(TreeNode* root, vector<int>&ve) {
        if(root == NULL) {
            return;
        }
        if(root -> left != NULL) {
            dfs(root -> left, ve);
        }
        if(root -> right != NULL) {
            dfs(root -> right, ve);
        }
        ve.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs(root, ans);
        return ans;
    }
};