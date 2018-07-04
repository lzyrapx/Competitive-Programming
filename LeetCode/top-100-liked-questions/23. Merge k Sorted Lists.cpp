/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Merge k sorted linked lists and return it as one sorted list.

class Solution {
public: 
    ListNode* merge(ListNode* l1, ListNode* l2)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0 ) return NULL;
        
        int n = lists.size(); // 链表个数
        
        while(n >= 2) // 直到划分成只有一个链表的任务
        {
            int k = (n + 1) / 2;  // k个链表先划分为合并两部分k / 2个链表的任务
            for(int i = 0; i < n / 2; i++) 
            {
                lists[i] = merge(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
};