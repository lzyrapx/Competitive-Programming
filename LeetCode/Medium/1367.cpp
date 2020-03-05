/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-04 23:09:47
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    bool dfs(ListNode* head, TreeNode* root) {
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(head -> val == root -> val) {
            return dfs(head -> next, root -> right) || dfs(head -> next, root -> left);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        return dfs(head, root) || isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }
};