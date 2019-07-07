#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *head; //虚拟头部
        ListNode *p;
        if (pHead1 == nullptr)
        {
            return pHead2;
        }
        if (pHead2 == nullptr)
        {
            return pHead1;
        }
        head = new ListNode(0);
        //head->next = pHead1->val <= pHead2->val ? pHead1 : pHead2;
        p = head;
        while ((pHead1 != nullptr || pHead2 != nullptr) && p != nullptr)
        {
            if (pHead1 == nullptr)
            {
                p->next = pHead2;
                break;
            }
            if (pHead2 == nullptr)
            {
                p->next = pHead1;
                break;
            }
            if (pHead1->val <= pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        return head->next;
    }
};
int main()
{
    return 0;
}