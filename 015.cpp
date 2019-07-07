#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个链表，反转链表后，输出新链表的表头。

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
//方法1：借用一个栈，系统栈容器栈都可以
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL)
            return NULL;
        return Reverse(NULL, pHead);
    }

private:
    ListNode *Reverse(ListNode *last, ListNode *current)
    {
        if (current != NULL)
        {
            ListNode *ans = Reverse(current, current->next);
            current->next = last;
            return ans;
        }
        else
        {
            return last;
        }
    }
};

//方法2：借用一个辅助指针
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *p1, *p2, *p3;
        if (pHead == nullptr)
        {
            return nullptr;
        }
        p1 = pHead->next;
        p2 = pHead;
        pHead->next = nullptr;
        while (p1 != nullptr)
        {
            p3 = p1;
            p1 = p1->next;
            p3->next = p2;
            p2 = p3;
        }
        return p2;
    }
};
int main()
{
    return 0;
}