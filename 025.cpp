#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
#define nullptr NULL
char Glevel = 'a';
struct RandomListNode
{
    int label;
    char level;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), level(Glevel), next(NULL), random(NULL)
    {
    }
};
void print(RandomListNode *pHead)
{
    RandomListNode *p;
    p = pHead;
    while (p != nullptr)
    {
        cout << " " << p->label << " " << p->level;
        p = p->next;
    }
    cout << endl;
}
class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        //Glevel = 'b';
        RandomListNode *pOld;
        RandomListNode *pNew;
        RandomListNode *pTmp;
        if (pHead == nullptr)
        {
            return nullptr;
        }
        pOld = pHead;
        while (pOld != nullptr)
        {
            pNew = new RandomListNode(pOld->label);
            pNew->next = pOld->next;
            pOld->next = pNew;
            pOld = pNew->next;
        }
        pOld = pHead;
        pNew = pOld->next;
        while (pNew->next != nullptr)
        {
            if (pOld->random != nullptr)
            {
                pNew->random = pOld->random->next;
            }
            pOld = pNew->next;
            pNew = pOld->next;
        }
        pOld = pHead;
        pTmp = pOld->next;
        while (pOld->next->next != nullptr)
        {
            pNew = pOld->next;
            pOld->next = pNew->next;
            pNew->next = pOld->next->next;
            pOld = pOld->next;
        }
        pOld->next = nullptr;
        return pTmp;
    }
};

int main()
{
    RandomListNode *pHead;
    RandomListNode *p;
    pHead = new RandomListNode(99);
    p = pHead;
    for (int i = 0; i < 10; i++)
    {
        p->next = new RandomListNode(i);
        p = p->next;
    }
    print(pHead);
    Solution s;
    p = s.Clone(pHead);
    print(pHead);
    print(p);
    return 0;
}