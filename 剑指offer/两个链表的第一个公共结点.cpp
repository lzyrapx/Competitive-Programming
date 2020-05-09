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
    int getlength(ListNode* head)
    {
        int len = 0;
        while(head != NULL)
        {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* FindFirstCommonNode( ListNode* headA, ListNode* headB) {
        if(headA == NULL || headB == NULL ) return NULL;
        int lenA = getlength(headA);
        int lenB = getlength(headB);
        if(lenA < lenB)
        {
            for(int i = 0; i < lenB - lenA; i++)
            {
                headB = headB ->next;
            }
        }
        else{
            for(int i = 0; i < lenA - lenB; i++)
            {
                headA = headA -> next;
            }
        }
        while(headA != NULL && headB != NULL && headA != headB)
        {
            headA = headA -> next;
            headB = headB -> next;
        }
        if(headA == NULL && headB == NULL) return NULL;
        return headA;
    }
};