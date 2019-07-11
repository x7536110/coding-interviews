#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        return judge(sequence, 0, sequence.size() - 1);
    }

private:
    bool judge(vector<int> sequence, int begin, int end)
    {
        if (begin == end)
            return true;
        int i, j;
        for (i = begin; i < end - 1; i++)
            if (sequence[i] > sequence[end])
            {
                i--;
                break;
            }
        for (j = end - 1; j > begin; j--)
            if (sequence[j] < sequence[end])
            {
                j++;
                break;
            }
        if (j - i > 1)
            return false;
        return judge(sequence, begin, i) && judge(sequence, j, end - 1);
    }
};
int main()
{
    return 0;
}