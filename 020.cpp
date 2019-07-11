#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

//增加一个辅助栈，记录“当前状态下，栈内最小的元素”即可
class Solution
{
public:
    void push(int value)
    {
        if (minStack.empty())
        {
            minStack.push(value);
        }
        else if (value <= minStack.top())
        {
            minStack.push(value);
        }
        nStack.push(value);
    }
    void pop()
    {
        if (minStack.top() == nStack.top())
        {
            minStack.pop();
        }
        nStack.pop();
    }
    int top()
    {
        return nStack.top();
    }
    int min()
    {
        return minStack.top();
    }

private:
    stack<int> nStack;
    stack<int> minStack;
};
int main()
{
    return 0;
}