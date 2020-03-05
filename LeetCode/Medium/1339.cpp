/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-05 00:17:18
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
    long long mod = 1e9 + 7;
    long long sum = 0;
    long long ans = 0;
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        sum += root -> val;
        dfs(root -> left);
        dfs(root -> right);
    }
    long long find_max(TreeNode* root) {
        if(root == NULL) return 0;
        long long s = root -> val + find_max(root -> left) + find_max(root -> right);
        ans = max(1LL * ans, s * (sum - s));
        return s;
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        find_max(root);
        return ans % mod;
    }
};