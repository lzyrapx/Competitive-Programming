/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-31 00:18:38
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>>ans;
        queue<TreeNode*>que;
        que.push(root);
        int depth = 0;
        while(!que.empty()) {
            vector<int>tmp;
            int n = que.size();
            for(int i = 0; i < n; i++) {
                TreeNode* cur = que.front();
                que.pop();
                // cout << cur -> val << endl;
                tmp.push_back(cur -> val);
                if(cur -> left) {
                    que.push(cur -> left);
                }
                if(cur -> right) {
                    que.push(cur -> right);
                }
            }
            if(depth % 2 == 1) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
            depth++;
        }
        return ans;
    }
};