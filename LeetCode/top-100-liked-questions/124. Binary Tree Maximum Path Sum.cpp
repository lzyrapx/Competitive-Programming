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
    int dfs(TreeNode* root, int &maxSum)
    {
        if(root == NULL) return 0;
        
        int l = max(0, dfs(root -> left, maxSum));
        int r = max(0, dfs(root -> right, maxSum));
        
        maxSum = max(maxSum, l + r + root -> val);
        // 返回以当前root为根的子树的最大路径和
        return max(l , r) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};