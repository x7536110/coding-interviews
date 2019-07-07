#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
class Solution
{
public:
    int NumberOf1(int n)
    {
        int i = 0;
        while (n)
        {
            n &= (n - 1);
            i++;
        }
        return i;
    };
};
int main()
{
    return 0;
}