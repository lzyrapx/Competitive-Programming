/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 17:19:21
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()) {
            int sz = que.size();
            long long sum = 0;
            for(int i = 0; i < sz; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if(cur -> left != NULL) {
                    que.push(cur -> left);
                }
                if(cur -> right != NULL) {
                    que.push(cur -> right);
                }
                sum += cur -> val;
            }
            ans.push_back(1.0 * sum / sz);
        }
        return ans;
    }
};