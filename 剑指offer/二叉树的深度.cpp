/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
       if(root == NULL) return 0;
       int left = TreeDepth(root->left);
       int right = TreeDepth(root->right);
       return max(left+1,right+1);
    }
};

------------------------------------------

class Solution {
public:
    // 层序遍历
    int TreeDepth(TreeNode* root)
    {
       if(root == NULL) return 0;
       queue<TreeNode*>que;
       int depth = 0;
       que.push(root);
       while(!que.empty())
       {
           int sz = que.size();
           depth ++;
           for(int i = 1; i <= sz; i++)
           {
               TreeNode* cur = que.front();
               que.pop();
               if(cur -> left != NULL) que.push(cur->left);
               if(cur -> right != NULL) que.push(cur->right);
           }
       }
       return depth;
    }
};