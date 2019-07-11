#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;
//输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        traversing(root, expectNumber, 0);
        sort(_ret.begin(), _ret.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.size() > b.size();
        });
        return _ret;
    }
    void traversing(TreeNode *node, int expectNumber, int sum)
    {
        if (node == nullptr)
            return;
        path.push_back(node->val);
        sum += node->val;
        if (sum == expectNumber && node->left == nullptr && node->right == nullptr)
        {
            vector<int> ret;
            for (auto i : path)
            {
                ret.push_back(i);
            }
            _ret.push_back(ret);
        }
        else if (sum < expectNumber)
        {
            traversing(node->left, expectNumber, sum);
            traversing(node->right, expectNumber, sum);
        }
        path.pop_back();
        return;
    }

private:
    vector<int> path;
    vector<vector<int>> _ret;
};
int main()
{
    return 0;
}