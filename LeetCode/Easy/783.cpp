/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-08 00:22:44
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
    // any two different node
    // 其实就是一个中序遍历
    int ans = INT_MAX, pre = -1;
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left != NULL) {
             minDiffInBST(root -> left);
        }
        if(pre >= 0) {
            ans = min(ans, root -> val - pre);
        }
        pre = root -> val;
        if(root -> right != NULL) {
            minDiffInBST(root -> right);
        }
        return ans;
    }
};