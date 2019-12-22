/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-29 00:01:31
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if((root -> val - p -> val) * (root -> val - q -> val) <= 0) return root;
        else if((root -> val > q -> val) && (root -> val > p -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        else {
            return lowestCommonAncestor(root -> right, p, q);
        }
    }
};