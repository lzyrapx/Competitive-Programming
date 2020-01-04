/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 15:43:11
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
    // between any two nodes....
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*>que;
        que.push(root);
        vector<int>ve;
        while(!que.empty()) {
            TreeNode* curNode = que.front();
            que.pop();
            int cur = curNode -> val;
            ve.push_back(cur);
            if(curNode -> left != NULL) {
                que.push(curNode -> left);
            }
            if(curNode -> right != NULL) {
                que.push(curNode -> right);
            }
        }
        int ans = 1e9;
        sort(ve.begin(), ve.end());
        for(int i = 1; i < ve.size(); i++) {
            ans = min(ans, ve[i] - ve[i - 1]);
        }
        return ans;
    }
};