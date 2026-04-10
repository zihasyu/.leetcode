

/*
已知一个二叉树根节点root，二叉树中每个节点都有个权重value；从根节点到一个叶节点路径上所有节点权重和称之为"子权重和"，问所有"子权重和"的最大值是多少？
struct Link
{
int value;
Link *left;
Link *right;
};
int max_value(Link * root) {}
*/

#include <iostream>
using namespace std;

struct Link
{
    int value;
    Link *left;
    Link *right;
};

int ans = INT_MIN;
int path = 0;

void dfs(Link *node)
{
    if (node == nullptr)
    {
        ans = max(ans, path);
        return;
    }
    path += node->value;
    dfs(node->left);
    dfs(node->right);
    path -= node->value;
    return;
}

int max_value(Link *root)
{
    ans = INT_MIN;
    if (root != nullptr)
        dfs(root);
    else
        return 0;
    return ans;
}