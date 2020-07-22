/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-22 23:48:45
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
    // 中序遍历
    void dfs(TreeNode* root, vector<int>&v) {
        if(root == NULL) {
            return;
        }
        dfs(root -> left, v);
        v.push_back(root -> val);
        dfs(root -> right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        dfs(root, v);
        return v[k-1];
    }
};