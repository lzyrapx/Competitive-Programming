/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* pre = NULL;
        ListNode* now = head;
        while(now != NULL)
        {
            ListNode* tmp = now -> next;
            now -> next = pre;
            pre = now;
            now = tmp;
        }
        return pre;
    }
};