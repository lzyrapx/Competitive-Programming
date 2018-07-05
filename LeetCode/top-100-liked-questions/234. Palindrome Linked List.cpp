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
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* nxt = NULL;
        while(head != NULL)
        {
            nxt = head -> next;
            head -> next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL ||head -> next ==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next ->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = reverse(slow -> next); //从slow -> next开始翻转
        
        ListNode* rev = slow -> next;
        
        while(rev != NULL)
        {
            if(head -> val != rev -> val)
            {
                return false;
            }
            head = head -> next;
            rev = rev -> next;
        }
        return true;
    }
};