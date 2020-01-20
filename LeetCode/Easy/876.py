'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 20:43:54
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        cur = head
        cnt = 0
        while cur:
            cur = cur.next
            cnt += 1
        
        cur = head
        for i in range(cnt // 2):
            cur = cur.next
        return cur
        
        