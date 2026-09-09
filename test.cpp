

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