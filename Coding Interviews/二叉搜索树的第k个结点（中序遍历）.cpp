/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
/*
二叉搜索树按照中序遍历的顺序打印出来正好就是排序好的顺序。
按照中序遍历顺序找到第k个结点就是所求。
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL) return NULL;
        if(k <= 0) return NULL;
        int cnt = 0;
        stack<TreeNode*>sta;
        TreeNode* root = pRoot;
        while(root != NULL || !sta.empty())
        {
            while(root != NULL)
            {
                sta.push(root);
                root = root -> left;
            }
            root = sta.top();sta.pop();
            cnt ++;
            if(cnt == k) return root;
            root = root -> right;
        }
        return NULL;
    }

    
};