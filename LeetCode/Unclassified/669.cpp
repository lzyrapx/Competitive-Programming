/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-24 23:54:21
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL) return NULL;
        if(root -> val >= L && R >= root -> val) {
            root -> left = trimBST(root -> left, L, R);
            root -> right = trimBST(root -> right, L, R);
        } else if(root -> val < L) {
            return trimBST(root -> right, L, R);
        } else {
            return trimBST(root -> left, L, R);
        }
        return root;
    }
};