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
    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        string ans;
        ans += to_string(t -> val);
        if(t -> left != NULL) {
            ans += "(" + tree2str(t->left) + ")";
        }
        else if(t -> right != NULL) {
            ans += "()";
        }
        if(t -> right != NULL) {
            ans +=  "(" + tree2str(t->right) + ")";
        }
        return ans;
    }
};