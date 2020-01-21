'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 22:30:49
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def solve(i):
            i = i[::-1]
            res = 0
            for c in range(len(i)):
                res += (1 << c) * int(i[c])
            return res
        
        if not root:
            return 0
        ans = []
        stack = []
        stack.append((root, str(root.val)))
        while len(stack) > 0:
            cur, path = stack.pop()
            if not cur.left and not cur.right:
                ans.append(path)
            if cur.left:
                stack.append((cur.left, path+str(cur.left.val)))
            if cur.right:
                stack.append((cur.right, path+str(cur.right.val)))
        Sum = 0
        for i in ans:
            Sum += solve(i)
        return Sum
       
        