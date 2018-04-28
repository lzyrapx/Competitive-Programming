/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
解题思路：
1.将左子树构造成双链表，并返回链表头节点。
2.定位至左子树双链表最后一个节点。
3.如果左子树链表不为空的话，将当前root追加到左子树链表。
4.将右子树构造成双链表，并返回链表头节点。
5.如果右子树链表不为空的话，将该链表追加到root节点之后。
6.根据左子树链表是否为空确定返回的节点。
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(root == NULL) return NULL;
        if(root -> left == NULL && root -> right == NULL) return root;
        
        // 将左子树构造成双链表，并返回链表的头结点
        TreeNode* left = Convert(root -> left);
        TreeNode* pre = left;
        // 定位至左子树中双链表右子树最后一个节点
        while(pre != NULL && pre -> right != NULL) {
            pre = pre -> right;
        }
        // 如果左子树链表不为空的话，将当前root追加到左子树链表
        if(left != NULL) {
            pre -> right = root;
            root -> left = pre;
        }
        
        // 将右子树构造成双链表，并返回链表头节点
        TreeNode* right = Convert(root -> right);
        // 如果右子树链表不为空的话，将该链表追加到root节点之后
        if(right != NULL) {
            right -> left = root;
            root -> right = right;
        }
        // 根据左子树链表是否为空确定返回的节点
        return left != NULL? left : root;
   
    }
};