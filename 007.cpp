#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。 n <= 39 class Solution
class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            cache[n] = 1;
            return 1;
        }
        if (n == 2)
        {
            cache[n] = 1;
            return 1;
        }
        if (cache[n] == 0)
        {
            cache[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        }
        return cache[n];
    }

private:
    long long cache[40] = {0};
};

// DP version
// class Solution
// {
// public:
//     int Fibonacci(int n)
//     {
//         int f = 0, g = 1;
//         while (n--)
//         {
//             g += f;
//             f = g - f;
//         }
//         return f;
//     }
// };
int main()
{
    return 0;
}