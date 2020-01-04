/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 18:13:18
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
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        map<int,int>mp;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                TreeNode* cur = que.front();
                que.pop();
                mp[cur -> val]++;
                if(mp[cur -> val] >=  1 && mp[k - cur -> val] >= 1) {
                    mp[cur -> val] -= 1;
                    if(mp[k - cur -> val] > 0) {
                        return true;
                    }
                    else {
                        mp[cur -> val] += 1;
                    }
                }
                if(cur -> left != NULL) {
                    que.push(cur -> left);
                }
                if(cur -> right != NULL) {
                    que.push(cur -> right);
                }
            }
        }
        return false;
    }
};