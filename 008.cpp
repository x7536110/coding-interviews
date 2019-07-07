#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
class Solution
{
public:
    int jumpFloor(int number)
    {
        if (number == 1)
        {
            cache[1] = 1;
            return 1;
        }
        if (number == 2)
        {
            cache[2] = 2;
            return 2;
        }
        if (cache[number] == 0)
        {
            cache[number] = jumpFloor(number - 1) + jumpFloor(number - 2);
        }
        return cache[number];
    }

private:
    long long cache[40] = {0};
};
int main()
{
    return 0;
}