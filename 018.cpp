#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//操作给定的二叉树，将其变换为源二叉树的镜像。

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
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        return;
    }

private:
    TreeNode *tmp;
};
int main()
{
    return 0;
}