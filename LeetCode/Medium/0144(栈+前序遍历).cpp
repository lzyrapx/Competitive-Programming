/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-22 15:21:48
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) {
            return ans;
        }
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* rt = stk.top();
            stk.pop();
            ans.push_back(rt -> val);
            if(rt -> right) {
                stk.push(rt -> right);
            }
            if(rt -> left) {
                stk.push(rt -> left);
            }
        }
        return ans;
    }
};