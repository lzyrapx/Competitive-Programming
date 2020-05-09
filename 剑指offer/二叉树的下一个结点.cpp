/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    // 中序遍历顺序
    // 题目中的next指针是: 指向父结点的指针
    TreeLinkNode* GetNext(TreeLinkNode* node)
    {
        if(node == NULL ) return NULL;
        if(node -> right != NULL) {  //如果该节点有右子树，则找右子树的最左节点
            node = node -> right;
            while(node -> left != NULL) {
                node = node -> left;
            }
            return node;
        }
        // 没有右子树：
        // 如果该节点是其父节点的左孩子，则返回父节点。
        // 否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
        while(node -> next != NULL) {
            if(node == node -> next -> left) return node -> next;
            node = node -> next;
        }
        return NULL; // 退到了根节点仍没找到，则返回null
    }
};