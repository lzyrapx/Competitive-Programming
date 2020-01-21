'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 11:44:29
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def dfs(root, parent, v, dep):
            if not root:
                return
            if root.val == v:
                return (dep, parent.val)
            return dfs(root.left, root, v, dep + 1) or dfs(root.right, root, v, dep + 1);
        depth1 = dfs(root, root, x, 0)
        depth2 = dfs(root, root, y, 0)
        if depth1[0] == depth2[0] and depth1[1] != depth2[1]:
            return True
        else:
            return False