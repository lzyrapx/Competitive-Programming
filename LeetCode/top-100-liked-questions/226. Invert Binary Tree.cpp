/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
------------------------------------------------------dfs
class Solution {
public:
    TreeNode* dfs(TreeNode *root)
    {
        swap(root -> left, root -> right);
        if(root -> left) dfs(root -> left);
        if(root -> right) dfs(root -> right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        return dfs(root);
    }
};

------------------------------------------------------bfs
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
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            if(cur -> left != NULL) que.push(cur->left);
            if(cur -> right != NULL) que.push(cur->right);
            TreeNode* tmp = cur -> left;
            cur -> left = cur -> right;
            cur -> right = tmp;
        }
        return root;
    }
};