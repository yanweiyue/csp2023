#include <iostream>
#include <string>
using namespace std;

struct node
{
    char val;
    node *left;
    node *right;
    node(char v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

// 依据前序和中序建树
// 每次只得到前序第一个节点
// 然后从中序中找到左右子串，分别得到中序和前序的起始位序
node *buildTree(string pre, int pre_l, int pre_r, string mid, int mid_l, int mid_r)
{
    if (pre_l > pre_r || mid_l > mid_r)
    {
        return nullptr;
    }
    node *n = new node(pre[pre_l]);
    int pos = mid.find(pre[pre_l]);
    int l_len = pos - mid_l;
    n->left = buildTree(pre, pre_l + 1, pre_l + l_len, mid, mid_l, pos - 1);
    n->right = buildTree(pre, pre_l + l_len + 1, pre_r, mid, pos + 1, mid_r);
    return n;
}

void postTraverse(node *root)
{
    if (!root)
    {
        return;
    }
    postTraverse(root->left);
    postTraverse(root->right);
    cout << root->val;
}

int main()
{
    string preOrder, midOrder;
    cin >> midOrder >> preOrder;
    node *root = buildTree(preOrder, 0, preOrder.size() - 1, midOrder, 0, midOrder.size() - 1);
    postTraverse(root);
    return 0;
}