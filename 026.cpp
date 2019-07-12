#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

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
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        p = nullptr;
        if (pRootOfTree == nullptr)
        {
            return nullptr;
        }
        trans(pRootOfTree);
        return Head;
    }
    void trans(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        trans(node->left);
        set(node);
        trans(node->right);
    }
    void set(TreeNode *node)
    {
        node->left = p;
        if (p != nullptr)
        {
            p->right = node;
        }
        else
        {
            Head = node;
        }
        p = node;
    }

private:
    TreeNode *p;
    TreeNode *Head;
};
int main()
{
    return 0;
}