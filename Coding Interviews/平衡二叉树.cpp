class Solution {
public:
    /*
    如果二叉树的任意节点左右子树高度不能相差超过 1，它就是平衡二叉树.
    后续遍历时，遍历到一个节点，其左右子树已经遍历，依次自底向上判断，每个节点只需要遍历一次。
    */
    bool ok = true;
    // 求取节点的深度
    int getlength(TreeNode* root)
    {
        if(root == NULL) return false;
        int left = getlength(root -> left) + 1;
        int right = getlength(root -> right) + 1;
        if(abs(left - right) > 1) ok = false;
        return max(left,right);
    }
    bool IsBalanced_Solution(TreeNode* root) {
        getlength(root);
        return ok;
    }
};