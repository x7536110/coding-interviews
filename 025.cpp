#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        RandomListNode *newHead;
        RandomListNode *newNode;
        RandomListNode *p;
        RandomListNode *q;
        RandomListNode *t;
        if (pHead == nullptr)
            return nullptr;
        newHead = new RandomListNode(pHead->label);
        p = pHead;
        q = newHead;
        //clone一条无random关系的链表
        while (p->next != nullptr)
        {
            q->next = new RandomListNode(p->next->label);
            p = p->next;
            q = q->next;
        }

        //修改原链表指向，并记录迭代顺序
        p = pHead;
        q = newHead;
        while (q->next != nullptr)
        {
            oldList.push_back(p);
            t = p->next;
            p->next = q;
            p = t;
            q = q->next;
        }
        int i = 0;
        p = oldList[i++];
        q = newHead;
        //重建random关系
        while (q->next != nullptr)
        {
            if (p->random != nullptr)
            {
                p = p->random;
                q->random = p->next;
            }
            p = oldList[i++];
            q = q->next;
        }
        for (int i = 0; i < oldList.size() - 1; i++)
        {
            oldList[i]->next = oldList[i + 1];
        }
        oldList[oldList.size() - 1]->next = nullptr;
        return newHead;
    }

private:
    vector<RandomListNode *> oldList;
};
int main()
{
    return 0;
}