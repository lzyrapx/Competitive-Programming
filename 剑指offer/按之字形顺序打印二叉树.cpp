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
        vector<vector<int>>ans;
        if(root == NULL) return ans; 
        queue<TreeNode*>que;
        que.push(root);
        bool even = false;
        while(!que.empty()) {
            vector<int>tmp;
            int sz = que.size();
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
            if(even == true) { // 用了reverse, 面试官会说海量数据时效率根本就不行
                std::reverse(tmp.begin(),tmp.end());
            }
            ans.push_back(tmp);
            even = !even;
        }
        return ans;
    }
    
};