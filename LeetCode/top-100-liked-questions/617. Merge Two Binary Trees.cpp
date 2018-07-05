/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
-------------------------------------------------------------- dfs

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return NULL;
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        t1 -> val = t1 -> val + t2 -> val;
        t1 -> left = mergeTrees(t1 -> left, t2 -> left);
        t1 -> right = mergeTrees(t1 -> right, t2 -> right);
        return t1;
    }
};

-------------------------------------------------------------- bfs:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return NULL;
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        
        queue<TreeNode*>que1, que2;
        que1.push(t1);
        que2.push(t2);
        // 层序遍历
        while(!que1.empty() && !que2.empty())
        {
            TreeNode* cur1 = que1.front();
            que1.pop();
            
            TreeNode* cur2 = que2.front();
            que2.pop();
            
            cur1 -> val = cur1 -> val + cur2 -> val;
            
            if(cur1 -> left == NULL && cur2 -> left) {
                cur1 -> left = cur2 -> left;
            }
            else if(cur1 -> left && cur2 -> left) {
                que1.push(cur1 -> left);
                que2.push(cur2 -> left);
            }
            
            if(cur1 -> right== NULL && cur2 -> right) {
                cur1 -> right = cur2 -> right;
            }
            else if(cur1 -> right && cur2 -> right) {
                que1.push(cur1 -> right);
                que2.push(cur2 -> right);
            }
            
        }
        return t1;
    }
};