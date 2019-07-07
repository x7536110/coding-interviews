#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        _pre = pre;
        _vin = vin;
        return reConstruct(0, _pre.size() - 1, 0, _vin.size() - 1);
    }
    TreeNode *reConstruct(int preL, int preR, int vinL, int vinR)
    {
        if (preL > preR)
        {
            return nullptr;
        }
        int val = _pre[preL];
        TreeNode *p = new TreeNode(val);
        int newRoot = vinL;
        while (_vin[newRoot] != val)
            newRoot++;
        int leftLen = newRoot - vinL;
        p->left = reConstruct(preL + 1, preL + leftLen, vinL, vinL + leftLen - 1);
        p->right = reConstruct(preL + leftLen + 1, preR, vinL + leftLen + 1, vinR);
        return p;
    }

private:
    vector<int> _pre;
    vector<int> _vin;
};
int main()
{
    return 0;
}