/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 15:44:23
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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) return -1;
        queue<TreeNode*>que;
        que.push(root);
        int minn = root -> val;
        int sub =  INT_MAX;
        int secondMin = -1;
        while(!que.empty()) {
            TreeNode* curNode = que.front();
            que.pop();
            minn = min(curNode -> val, minn);
            if(sub >= curNode -> val - minn && curNode -> val != minn) {
                sub = curNode -> val - minn;
                secondMin = curNode -> val;
            }
            if(curNode -> left) {
                que.push(curNode -> left);
            }
            if(curNode -> right) {
                que.push(curNode -> right);
            }
        }
        return secondMin;
    }
};