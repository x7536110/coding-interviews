#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

//和008没区别，因为限定了2*n和2*1，所以只存在横/竖两个状态，可以看作N-1和N-2
class Solution
{
public:
    int rectCover(int number)
    {
        if (number == 0)
        {
            return 0;
        }
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
            cache[number] = rectCover(number - 1) + rectCover(number - 2);
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