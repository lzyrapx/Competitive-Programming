/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        queue<TreeNode*>que;
        que.push(root);
        vector<int>ans;
        while(!que.empty()) {
            int n = que.size();
            int max_val = INT_MIN;
            for(int i = 0; i < n; i++){
                TreeNode* cur = que.front();
                que.pop();
                max_val = max(max_val, cur -> val);
                if(cur -> left != NULL) {
                    que.push(cur -> left);
                }
                if(cur -> right != NULL) {
                    que.push(cur -> right);
                }
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};