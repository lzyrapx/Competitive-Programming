/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0  || vin.size() == 0) return NULL;
        if(pre.size() != vin.size()) return NULL;
        return contruct(pre,vin,0, pre.size() - 1, 0, vin.size() - 1);
    }
    TreeNode* contruct(vector<int>&pre, vector<int>&vin, int l1, int r1, int l2, int r2)
    {
        //新建一个tree
        TreeNode* root =  new TreeNode(pre[l1]);
        if(l1 == r1)
        {
            return root;
        }
        int Root = pre[l1]; //先序遍历第一个位置肯定是根节点node
        int rt = 0;
        // 对中序数组进行遍历，在中序遍历里找到对应的根节点位置
        for(rt = l2; rt <= r2; rt++)
        {
            if(vin[rt] == Root) break;
        }
        // 中序左子树的长度
        int left_tree_len = rt - l2;
        // 中序右子树的长度
        int right_tree_len = r2 - rt;
        // 中序遍历的根节点位置在中间 rt，在 rt 左边的肯定是node的左子树的中序子数组vin[left...rt-1], rt右边的肯定是node的右子树的中序子数组vin[rt+1...right]
        // 先序遍历的第二个位置到rt，即pre[left+1...rt]，为node左子树的先序子数组，剩下rt右边的 pre[rt+1...right]就是node的右子树的先序子数组
        if(left_tree_len > 0)
        {
            // 根节点 rt 的左子树，递归处理
            root -> left = contruct(pre , vin, l1 + 1, l1 + left_tree_len, l2 ,rt - 1);
        }
        if(right_tree_len > 0)
        {
            // 根节点 rt 的右子树，递归处理
            root -> right = contruct(pre, vin, l1 + 1 + left_tree_len, r1, rt + 1, r2);
        }
        return root;
    }
};