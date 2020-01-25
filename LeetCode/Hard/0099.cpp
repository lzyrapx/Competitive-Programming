/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-24 22:17:09
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
    // 采用中序遍历，但是只需要记录两个被错误交换的节点即可。
    // 遇到第一个比后面的数字大的节点，就记为first；
    // 遇到最后一个比前面的数字小的节点，就记为second
    // 最后交换first和second的值即可
    void inOrderTraverse(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        if(root == NULL) {
            return;
        }
        inOrderTraverse(root -> left, prev, first, second);
        if(prev != NULL && prev -> val > root -> val) {
            if(first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inOrderTraverse(root -> right, prev, first, second);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        inOrderTraverse(root, prev, first, second);
        swap(first -> val, second -> val);
        return;
    }
};