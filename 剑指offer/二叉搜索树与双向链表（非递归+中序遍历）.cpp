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
1.核心是中序遍历的非递归算法。
2.修改当前遍历节点与前一遍历节点的指针指向。
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(root == NULL) return NULL;
        if(root -> left == NULL && root -> right == NULL) return root;
        stack<TreeNode*>sta;
        TreeNode* cur = root;
        TreeNode* pre = NULL; //用于保存中序遍历序列的上一节点
        bool isFirst = true;
        while(cur != NULL || !sta.empty())
        {
            // 中序遍历, 先定位到最底的左子树
            while(cur != NULL) {
                sta.push(cur);
                cur = cur -> left;
            }
            cur = sta.top();
            sta.pop();
            if(isFirst) {
                root = cur;  // 将中序遍历序列中的第一个节点记为root
                pre = cur;
                isFirst = false;
            }
            else { // 修改当前遍历节点与前一遍历节点的指针指向
                pre -> right = cur;
                cur -> left = pre;
                pre = cur;
            }
            cur = cur -> right;
        }
        return root;
    }
};