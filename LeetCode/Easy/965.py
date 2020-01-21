'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 22:57:33
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        stack = []
        stack.append((root, root.val))
        pre = root.val
        while len(stack) > 0:
            cur, val =  stack.pop()
            if pre != val:
                return False
            
            pre = val
            
            if cur.left:
                stack.append((cur.left, cur.left.val))
            if cur.right:
                stack.append((cur.right,cur.right.val))
        return True
            
        