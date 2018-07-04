/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
用两个指针，pre和cur指针。首先cur指针先向前走N步，如果此时cur指向空，说明n为链表的长度，
则需要移除的为首元素，那么此时我们返回head->next即可，如果cur存在，我们再继续往下走，
此时pre指针也跟着走，直到cur为最后一个元素时停止，此时pre指向要移除元素的前一个元素，
我们再修改指针跳过需要移除的元素.。
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode* pre = head;
        ListNode* cur = head;
        for(int i = 0; i < n; i++)
        {
            cur = cur -> next;
        }
        if(cur == NULL) return head -> next;
        while(cur -> next != NULL)
        {
            cur = cur -> next;
            pre = pre -> next;
        }
        pre -> next = pre -> next -> next;
        return head;
    }
};