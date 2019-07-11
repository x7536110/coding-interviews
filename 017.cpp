#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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
    //外层方法中序遍历二叉树
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 == nullptr)
            return false;
        if (pRoot2 == nullptr)
            return false;
        return hasSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    //内层方法从任意节点开始判断是否为子结构
    bool hasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr)
            return false;
        if (pRoot1->val == pRoot2->val)
        {
            return hasSubtree(pRoot1->left, pRoot2->left) && hasSubtree(pRoot1->right, pRoot2->right);
        }
        return false;
    }
};
int main()
{
    return 0;
}