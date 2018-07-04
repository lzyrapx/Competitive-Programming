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
    // 其实是个中序遍历
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root -> right == NULL && root -> left == NULL) return true;
        stack<TreeNode*>s;
        TreeNode* pre = NULL;
        while(root || !s.empty())
        {
            while(root != NULL) { // 定位到最左子节点
                s.push(root);
                root = root -> left;
            }
            root = s.top(); s.pop();
            // 利用二叉搜索树中序遍历的有序性, 左子树 < 根 < 右子树
            // 中序遍历的出栈时判断当前出栈值是否小于之前之前的节点的值。
            // 出栈次序是: 左子树 -> 根 -> 右子树
            // cout << root -> val << endl;
            if(pre != NULL && pre ->val >= root -> val) { 
                return false;
            }
            pre = root;
            root = root -> right;
        }
        return true;
    }
};