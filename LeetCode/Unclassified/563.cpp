/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 16:51:13
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
    int findsum(TreeNode* root) {
        if(root == NULL) return 0;
        return root -> val + findsum(root -> left) + findsum(root -> right);
    }
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        int leftSum = findsum(root -> left);
        int rightSum = findsum(root -> right);
        sum = abs(leftSum - rightSum);
        return sum + findTilt(root -> left) + findTilt(root -> right);
    }
};