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
    // 尽量不要用reverse
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans; 
        queue<TreeNode*>que;
        que.push(root);
        int even = 0;
        while(!que.empty())
        {
            vector<int>tmp(que.size());
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                TreeNode *cur = que.front();
                que.pop();
                if(cur -> left != NULL) {
                    que.push(cur -> left);
                }
                if(cur -> right != NULL) {
                    que.push(cur -> right);
                }
                int id;
                if(even == 0) {
                    id = i;
                }
                else{
                    id = sz - 1 - i;
                }
                tmp[id] = cur -> val;
            }
            even = !even;
            ans.push_back(tmp);
        }
        return ans;
    }
    
};