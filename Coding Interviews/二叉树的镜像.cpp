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
	// 递归
    void Mirror(TreeNode *root) {
        if(root == NULL) return;
         // 先交换当前节点的两个子树节点
        TreeNode* tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
        
        Mirror(root -> left);
        Mirror(root -> right);
    }
};

-------------------------------------------------

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
    // 非递归, 层次遍历
    void Mirror(TreeNode *root) 
    {
        if(root == NULL) return;
        vector<TreeNode*> vv;
        vv.push_back(root);
        while (!vv.empty()) 
        {
            vector<TreeNode*> t;
            for (auto &cur : vv) 
            {
                swap(cur->left, cur->right);
                if (cur->left) t.push_back(cur->left);
                if (cur->right) t.push_back(cur->right);
            }
            vv = t;
        }
    }
};