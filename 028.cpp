#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

//如果存在这样一个数字，那么他出现次数一定大于其他数字出现次数之和
//遍历整个数组，只记录“当前数字与已经便利过的数字出现次数抵消值”，如果存在一个这样的数字，那么他最后的抵消值一定大于0
//最后判断这个数字的实际出现次数是否大于一半就可以了
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int t = 0;
        int num = 0;
        if (numbers.size() == 0)
            return 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (t == numbers[i])
                num++;
            else if (num == 0)
            {
                t = numbers[i];
                num++;
            }
            else
                num--;
        }
        if (num > 0)
        {
            int times = 0;
            for (int i = 0; i < numbers.size(); i++)
                if (numbers[i] == t)
                    times++;
            if (times * 2 > numbers.size())
                return t;
            else
                return 0;
        }
        else
            return 0;
    }
};
int main()
{
    return 0;
}