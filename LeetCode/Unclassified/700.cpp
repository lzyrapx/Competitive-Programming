/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-23 23:50:14
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root -> val == val) return root;
        else if(root -> val > val) {
            return searchBST(root -> left, val);
        }
        else if(root -> val < val) {
            return searchBST(root -> right, val);
        }
        return root;
    }
};