/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-25 23:25:49
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL) return NULL;
        if(root -> val < L) {
            return rangeSumBST(root -> right, L, R);
        }else if(root -> val > R) {
            return rangeSumBST(root -> left, L, R);
        }
        return root -> val + rangeSumBST(root -> left, L, R) + rangeSumBST(root -> right, L, R);
    }
};