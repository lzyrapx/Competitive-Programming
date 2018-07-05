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
    // 节点a与节点b的公共祖先c一定满足：a与b分别出现在c的左右子树上（如果a或者b本身不是祖先的话）
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode *L = lowestCommonAncestor(root -> left, p, q);
        TreeNode *R = lowestCommonAncestor(root -> right, p, q);
        
        if(L != NULL && R != NULL) return root;
        else return L != NULL ? L : R;
    }
};