/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 12:38:39
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
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) {
            return ans;
        }
        map<int,int>mp;
        queue<TreeNode*>que;
        que.push(root);
        long long  maxn = 0;
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            mp[cur -> val]++;
            maxn = max(maxn, 1LL * mp[cur -> val]);
            if(cur -> left != NULL) {
                que.push(cur -> left);
            }
            if(cur -> right != NULL) {
                que.push(cur -> right);
            }
        }
        for(auto x: mp) {
            if(x.second == maxn) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};