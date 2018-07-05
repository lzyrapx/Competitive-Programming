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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            int n = que.size();
            vector<int>tmp;
            for(int i = 0; i < n; i++) {
                TreeNode* cur = que.front();
                que.pop();
                tmp.push_back(cur -> val);
                if(cur -> left) que.push(cur -> left);
                if(cur -> right) que.push(cur -> right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};