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
    // 中序遍历
    void dfs(TreeNode* root, vector<int>&nodes)
    {
        if(root == NULL) return;
        dfs(root -> left, nodes);
        nodes.push_back(root -> val);
        dfs(root -> right, nodes);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>nodes;
        dfs(root, nodes);
        return nodes;
    }
};