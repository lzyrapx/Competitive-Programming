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
    ListNode* FindKthToTail(ListNode* head,  int k) {
        if(head == NULL ) return NULL;
        if(k == 0) return NULL;
        
        ListNode* cur = head;
        ListNode* pre = head;
        for(int i = 1; i < k; i++)
        {
            if(cur -> next != NULL) cur = cur -> next;
            else return NULL;
        }
        while(cur -> next != NULL)
        {   
            cur = cur -> next;
            pre = pre -> next;
        }
        return pre;
    } 
};