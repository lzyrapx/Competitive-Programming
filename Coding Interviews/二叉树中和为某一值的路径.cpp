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
    vector<vector<int>>ans;
    vector<int>path;
    void dfs(TreeNode* root, int expectNumber)
    {
        path.push_back(root -> val);

        if(root -> val == expectNumber)
        {
            if(root -> left == NULL && root -> right == NULL) {
                ans.push_back(path);
            }
        }
        
        else{
            if(root -> left) dfs(root->left, expectNumber - (root -> val));
            if(root -> right) dfs(root->right,expectNumber - (root ->val));
        }
        path.pop_back(); //回溯
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL) return vector<vector<int>>();
        dfs(root,expectNumber);
        return ans;
    }
};