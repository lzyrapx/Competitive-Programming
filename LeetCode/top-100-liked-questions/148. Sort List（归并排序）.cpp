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
    ListNode* mergeSort(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val  < l2 -> val)
            {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        if(l1 != NULL) cur -> next = l1;
        if(l2 != NULL) cur -> next = l2;
        return dummy -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL ) return NULL;
        if(head -> next  == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* break_pos = head;
        while(fast != NULL && fast -> next != NULL) // 分开两段
        {
            break_pos = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        break_pos -> next = NULL;
        return mergeSort(sortList(head),sortList(slow));
    }
};