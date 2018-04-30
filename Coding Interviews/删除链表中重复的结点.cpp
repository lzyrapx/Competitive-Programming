/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head)
    {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        ListNode* ans = new ListNode(0);
        ans -> next = head;
        
        ListNode* pre = ans;
        while(pre -> next != NULL) {
            ListNode* cur = pre -> next;
            while(cur -> next != NULL && cur -> val == cur -> next -> val) {
                cur = cur -> next;
            }
            // 如果现指针和遍历时的第一个元素就不相同，则把前驱指针向下移一位。
            if(pre -> next != cur) {
                pre -> next = cur -> next;
            }
            else // 相同就跳过 pre -> next 这个节点
            {
                pre = pre -> next;
            }
        }
        return ans -> next;
    }
};