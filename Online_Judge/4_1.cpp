/*
问题 A: 二叉树调整
时间限制: 1 Sec  内存限制: 10 MB
提交: 117  解决: 37
[提交][状态][讨论版]
题目描述
对于一个完全二叉树，每个节点用来存储节点权重。我们定义，其中任意子树的重量为该子树内所有节点的权重和（包含该子树根节点的权重）。 

小蓝鲸麻烦你帮忙对该二叉树进行调整，对于任意节点，若左子树根节点的重量大于右子树根节点的重量（空子树的重量为0），则调换左右子树。


输入
第一行有一个数字 N， 表示完全二叉树的节点个数。

第二行为 N 个正整数 ai>0，表示完全二叉树的数组存储表示。（N≤100000）

输出
输出调整后的二叉树中序遍历结果，以空格分隔。



样例输入
6
3 2 1 4 5 6
样例输出
1 6 3 4 2 5
*/
#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int val;
    int origin;
    Node* left;
    Node* right;
    Node* parent;
};
 
int print(Node* a)
{
    if (a == NULL)
        return 0;
    print(a->left);
    cout << a->origin << " ";
    print(a->right);
    return 0;
}
 
int count(Node* a)
{
    if (a == NULL)
        return 0;
    a->val += count(a->left) + count(a->right);
    return a->val;
}
 
Node* my_swap(Node* a)
{
    if (a->left == NULL && a->right == NULL)
    {
        return a;
    }
    if (a->right == NULL)
    {
        Node* temp = a->left;
        a->left = a->right;
        a->right = temp;
        return a;
    }
    my_swap(a->left);
    my_swap(a->right);
    if (a->left->val > a->right->val)
    {
        Node* temp = a->left;
        a->left = a->right;
        a->right = temp;
        return a;
    }
}
int main()
{
    int num(0);
    cin >> num;
    vector<Node*> opr;
    Node root;
    cin >> root.val;
    root.origin = root.val;
    root.left = NULL;
    root.right = NULL;
    root.parent = NULL;
    opr.push_back(&root);
    for (int i(1); i < num; i++)
    {
        Node* temp = new Node;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;
        cin >> temp->val;
        temp->origin = temp->val;
        if (opr[0]->left == NULL)
        {
            opr[0]->left = temp;
            temp->parent = opr[0];
            opr.push_back(temp);
            continue;
        }
        if (opr[0]->right == NULL)
        {
            opr[0]->right = temp;
            temp->parent = opr[0];
            opr.erase(opr.begin());
            opr.push_back(temp);
            continue;
        }
    }
    count(&root);
    my_swap(&root);
    print(&root);
    return 0;
}
 
/**************************************************************
    Problem: 1177
    User: 181860077
    Language: C++
    Result: 正确
    Time:692 ms
    Memory:4048 kb
****************************************************************/
