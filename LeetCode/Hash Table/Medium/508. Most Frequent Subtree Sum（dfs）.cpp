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
    int dfs(TreeNode* root, map<int,int>&mp) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) {
            mp[root -> val]++;
            return root -> val;
        }
        int lsum = dfs(root -> left, mp);
        int rsum = dfs(root -> right, mp);
        mp[root -> val + lsum + rsum]++;
        return root -> val + lsum + rsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        map<int,int>mp;
        dfs(root,mp);
        int maxnum = 0;
        for(auto x : mp) 
        {
            if(x.second > maxnum) {
                maxnum = x.second;
                ans.clear();
                ans.push_back(x.first);
            }
            else if(x.second == maxnum) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};