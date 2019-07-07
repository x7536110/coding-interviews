#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

//要考虑负幂的情况
class Solution
{
public:
    double Power(double base, int exponent)
    {
        double ans = base;
        if (exponent == 0)
            return 1;
        else
        {
            for (int i = 1; i < abs(exponent); i++)
            {
                ans *= base;
            }

            if (exponent < 0)
                ans = 1 / ans;
        }
        return ans;
    }
};
int main()
{
    return 0;
}