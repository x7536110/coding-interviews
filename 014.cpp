#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个链表，输出该链表中倒数第k个结点。

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
//双指针法，一个指针比另一个晚出发K步，当第一个指针到达终点时，第二个指针就是倒数第K个
//牛客的数据比较恶心，会有nullptr输入
class Solution
{
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        ListNode *p1;
        ListNode *p2;
        p1 = p2 = pListHead;
        if (pListHead == nullptr || k <= 0)
            return nullptr;
        while (--k)
        {
            if (p1->next == nullptr)
                return nullptr;
            p1 = p1->next;
        }
        while (p1->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
int main()
{
    return 0;
}