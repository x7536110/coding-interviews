#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
// 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

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
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> ret;
        stack<int> healper;
        while (head != nullptr)
        {
            healper.push(head->val);
            head = head->next;
        }
        while (!healper.empty())
        {
            ret.push_back(healper.top());
            healper.pop();
        };
        return ret;
    }
};
int main()
{
    return 0;
}