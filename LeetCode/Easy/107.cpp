/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 18:49:02
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()) {
            int sz = que.size();
            vector<int>ve;
            for(int i = 0; i < sz; i ++) {
                TreeNode* cur = que.front();
                que.pop();
                ve.push_back(cur->val);
                if(cur -> left) que.push(cur -> left);
                if(cur -> right) que.push(cur -> right);
            }
            ans.push_back(ve);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};