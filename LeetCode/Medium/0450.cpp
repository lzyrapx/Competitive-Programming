/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 删除二叉树里的一个节点，然后输出新的二叉树
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        if(root -> val == key) {
            if(root -> left == NULL && root -> right == NULL) {
                return NULL;
            }
            if(root -> left == NULL) {
                return root -> right;
            }
            if(root -> right == NULL) {
                return root -> left;
            }
            // 将删除节点的左孩子放到删除节点的右孩子的最左面节点的左孩子的位置
            if(root -> left != NULL && root -> right != NULL) {
                TreeNode* cur = root -> right;
                while(cur -> left != NULL) {
                    cur = cur -> left;
                }
                cur -> left = root -> left;
                root = root -> right;
                return root;
            }
        }
        if(root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        }
        if(root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        }
        return root;
    }
};