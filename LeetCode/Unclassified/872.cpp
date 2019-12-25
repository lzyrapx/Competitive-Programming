/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-25 23:46:46
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
    void getLeaves(TreeNode* root, vector<int>&ve) {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) {
            ve.push_back(root -> val);
        }
        else {
            getLeaves(root -> left, ve);
            getLeaves(root -> right, ve);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaves1,leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        if(leaves1 == leaves2) return true;
        else return false;
    }
};