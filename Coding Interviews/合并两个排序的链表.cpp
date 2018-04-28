/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* l1, ListNode* l2)
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
};