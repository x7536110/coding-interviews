#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> answer;
        if (str.empty())
            return answer;
        sort(str.begin(), str.end());
        do
        {
            answer.push_back(str);
        } while (next_permutation(str.begin(), str.end()));
        return answer;
    }
};
int main()
{
    return 0;
}