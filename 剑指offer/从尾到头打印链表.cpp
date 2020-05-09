/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head == NULL) return vector<int>();
        vector<int>ans;
        stack<ListNode*>sta;
        ListNode* cur = head;
        while(cur != NULL)
        {
            sta.push(cur);
            cur = cur -> next;
        }
        while(!sta.empty())
        {
            cur = sta.top();
            ans.push_back(cur->val);
            sta.pop();
        }
        return ans;
    }
};