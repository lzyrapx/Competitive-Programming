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
    // 把二叉树展开成链表，形成的链表的顺序分析出是使用先序遍历
    /*
    思路：
    思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，
    然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。
    */
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root -> left); //处理左子树
        flatten(root -> right);//处理右子树
        
        TreeNode* tmp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
        while(root -> right) root = root -> right;
        root -> right = tmp;
    }
};
/*
过程：
     1
    / \
   2   5
  / \   \
 3   4   6

     1
    / \
   2   5
    \   \
     3   6
      \    
       4

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/