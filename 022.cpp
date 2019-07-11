#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        q.push(root);
        TreeNode *p;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p->left != nullptr)
            {
                q.push(p->left);
            }
            if (p->right != nullptr)
            {
                q.push(p->right);
            }
            v.push_back(p->val);
        }
        return v;
    }

private:
    queue<TreeNode *> q;
};
int main()
{
    return 0;
}