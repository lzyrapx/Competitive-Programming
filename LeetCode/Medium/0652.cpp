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
    // 给你一棵而测试，找到所有重复了的子树，同类型的就输出其中一个即可
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string, int>mp;
        dfs(ans, mp, root);
        return ans;
    }
    string dfs(vector<TreeNode*>&ans, unordered_map<string, int>&mp, TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string str;
        str = to_string(root -> val) + " " + dfs(ans, mp, root -> left) + " " + dfs(ans, mp, root -> right);
        if(mp[str] == 1) {
            ans.push_back(root);
        }
        mp[str]++;
        return str;
    }
};