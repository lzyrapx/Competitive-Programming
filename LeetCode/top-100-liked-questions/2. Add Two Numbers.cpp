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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL) {
            return NULL;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* cur = ans;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int v1 = l1 != NULL ?  l1 -> val : 0;
            int v2 = l2 != NULL ?  l2 -> val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            cur -> next = new ListNode (sum % 10);
            cur = cur -> next;
            if(l1 != NULL) l1 = l1 -> next;
            if(l2 != NULL) l2 = l2 -> next;
        }
        if(carry!=0) {
            cur -> next = new ListNode(1);
        }
        return ans -> next;
    }
};