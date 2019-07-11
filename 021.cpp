#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int i = 0;
        int j = 0;
        int len = pushV.size();
        while (j < len)
        {
            while (s.empty() || s.top() != popV[j])
            {
                if (i == len)
                    return false;
                s.push(pushV[i++]);
            }
            s.pop();
            if (s.empty() && j == len - 1)
            {
                return true;
            }
            j++;
        }
        return false;
    }

private:
    stack<int> s;
};

int main()
{
    return 0;
}