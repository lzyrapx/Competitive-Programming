/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    /*
1. 在原链表的每个节点后面拷贝出一个新的节点。
2. 依次给新的节点的随机指针赋值，而且这个赋值非常容易：
    cur->next->random = cur->random->next。
3. 断开链表可得到深度拷贝后的新链表。
*/
    RandomListNode* Clone(RandomListNode* head)
    {
        if(head == NULL) return NULL;
        RandomListNode* cur = head;
        // 在原链表的每个节点后面拷贝出一个新的节点。
        while(cur != NULL)
        {
            RandomListNode* node = new RandomListNode(cur -> label);
            node -> next = cur -> next;
            cur -> next = node;
            cur = node -> next;
        }
        // 依次给新的节点的随机指针赋值
        cur = head;
        while(cur != NULL)
        {
            if(cur -> random != NULL)
            {
                cur -> next -> random = cur -> random -> next;
            }
            cur = cur -> next -> next;
        }
        // 断开链表可得到深拷贝后的新链表
        cur = head;
        RandomListNode* ans = head -> next;
        while(cur != NULL)
        {
            RandomListNode* tmp = cur -> next;
            cur -> next = cur -> next -> next;
            if(tmp -> next != NULL) {
                tmp -> next = tmp -> next -> next;
            }
            cur = cur -> next;
        }
        return ans;
    }
};