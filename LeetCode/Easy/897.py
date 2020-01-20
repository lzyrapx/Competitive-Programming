'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 20:24:46
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def dfs(cur, pre):
            if cur is None: return pre
            rt = dfs(cur.left, cur)
            cur.left, cur.right = None, dfs(cur.right, pre)
            return rt
        if root is None: return None
        return dfs(root, None)
        