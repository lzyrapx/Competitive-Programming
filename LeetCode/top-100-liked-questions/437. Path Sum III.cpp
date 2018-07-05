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
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        int ans = 0;
        dfs(root, ans, sum);
        return ans + pathSum(root -> left, sum) + pathSum(root -> right, sum);
    }
    void dfs(TreeNode* root, int &ans, int sum)
    {
        if(root == NULL) return ;
        int remain = sum - root -> val;
        if(remain == 0) ans++;
        dfs(root -> left, ans, remain);
        dfs(root -> right, ans, remain);
    }
};