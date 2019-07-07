#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//方案1：拆分成两个有序序列，重组
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> temp;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 1)
                temp.push_back(array[i]);
        }
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 0)
                temp.push_back(array[i]);
        }
        for (int i = 0; i < array.size(); i++)
        {
            array[i] = temp[i];
        }
    }
};

//方案2：实现一个按奇偶为置换依据的冒泡排序
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int temp;
        int len = array.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = len - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                {
                    temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                }
            }
        }
    }
};
int main()
{
    return 0;
}