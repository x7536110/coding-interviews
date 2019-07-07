#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
// 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution
{
public:
    bool Find(int target, vector<vector<int> > array)
    {
        int col_len = array.size();
        int row_len = array[0].size();
        int c = col_len - 1;
        int r = 0;
        int now = 0;
        while (r < row_len && c >= 0)
        {
            now = array[c][r];
            if (now == target)
            {
                return true;
            }
            if (now > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
};
int main()
{
    return 0;
}