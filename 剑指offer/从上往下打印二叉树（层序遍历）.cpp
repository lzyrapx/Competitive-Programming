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
    // 层序遍历...
    vector<int> PrintFromTopToBottom(TreeNode* root) {
       vector<int>ans;
       if(root==NULL) return ans;
       queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            ans.push_back(cur -> val);
            if(cur -> left != NULL) {
                que.push(cur->left);
            }
            if(cur->right != NULL) {
                que.push(cur->right);
            }
        }
        return ans;
    }
};