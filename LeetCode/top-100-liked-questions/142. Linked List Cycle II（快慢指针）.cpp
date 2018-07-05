/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
快慢指针，记录两个指针相遇的位置，当两个指针相遇了后，让另一指针从链表头开始。
两个指针每次走一步，再相遇的位置就是链表中环的起始位置。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) break;
            if(fast == NULL || fast -> next == NULL) return NULL;
        }
        if(fast == NULL || fast -> next == NULL) return NULL;
        
        ListNode* start = head;
        while(start != fast)
        {
            start = start -> next;
            fast = fast -> next;
        }
        return start;
    }
};