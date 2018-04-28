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
    ListNode* ReverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL)
        {
            ListNode* tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};