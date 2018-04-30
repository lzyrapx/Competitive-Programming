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
class Solution {
public:
        vector<vector<int> > Print(TreeNode* root) {
          vector<vector<int>> ans;
            if(root == NULL) return ans;
            queue<TreeNode*>que;
            que.push(root);
            while(!que.empty()) {
                int sz = que.size();
                vector<int>tmp;
                for(int i = 0; i < sz; i++) {
                    TreeNode* cur = que.front();
                    que.pop();
                    tmp.push_back(cur -> val);
                    if(cur -> left != NULL) {
                        que.push(cur -> left);
                    }
                    if(cur -> right != NULL) {
                        que.push(cur -> right);
                    }
                }
                ans.push_back(tmp);
            }
            return ans;
        }
    
};