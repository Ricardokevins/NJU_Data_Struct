/*
问题 B: 小蓝鲸挂灯笼
时间限制: 1 Sec  内存限制: 10 MB
提交: 718  解决: 104
[提交][状态][讨论版]
题目描述
为了迎接圣诞节的到来，小蓝鲸的寝室准备挂上灯笼。现在有n个灯笼，灯笼的编号记为0~n-1，这些灯笼之间已经有m条电线连接，并且电线之间没有回路。由于小蓝鲸的寝室只有一个挂钩，因此这串灯笼中只有一个可以挂上去，记为“根灯笼”，其余灯笼是垂下的。为了避免灯笼挂的过高，小蓝鲸需要找到使这串灯笼高度最小的“根灯笼”。

输入
第一行：n m，n是灯笼的个数，m是电线的个数（1 ≤ n ≤ 50000，0 ≤ m ≤ 49999）

第二行~第m+1行：每根电线连接的两个灯笼的编号，用空格隔开。

输出
使高度最小的“根灯笼”的编号，按照从小到大排列，用空格隔开。

样例输入
4 3
1 0
1 2
1 3
样例输出
1
提示
*/

#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int val;
    int balance;
    Node* left;
    Node* right;
    Node* parent;
};
struct Tree {
    Node* head;
}AVL_TREE;
 
int height(Node* a)
{
    if (a == NULL)
    {
        return 0;
    }
    int left_h = height(a->left);
    int right_h = height(a->right);
    return left_h > right_h ? left_h + 1 : right_h + 1;
}
Node* find(int val, Node* head)
{
    if (head == NULL)
        return 0;
    if (head->val == val)
        return head;
    if (head->val > val)
    {
        if (head->left)
        {
            return find(val, head->left);
        }
        else
        {
            return head;
        }
    }
    else
    {
        if (head->right)
        {
            return find(val, head->right);
        }
        else
        {
            return head;
        }
    }
}
void count_balance(Node *a)
{
    if (a)
    {
        a->balance = height(a->right) - height(a->left);
    }
}
Node* Tleft(Node* a)
{
    Node* temp = a->right;
    if (a->parent != NULL)
    {
        if (a->parent->right == a)
        {
            a->parent->right = temp;
        }
        else
        {
            a->parent->left = temp;
        }
    }
    temp->parent = a->parent;
    a->parent = temp;
    a->right = temp->left;
    temp->left = a;
    if (a->right != NULL)
    {
        a->right->parent = a;
    }
    count_balance(a);
    count_balance(temp);
    return temp;
}
Node* Tright(Node* a)
{
    Node* temp = a->left;
    if (a->parent != NULL)
    {
        if (a->parent->left == a)
        {
            a->parent->left = temp;
        }
        else
        {
            a->parent->right = temp;
        }
    }
    temp->parent = a->parent;
    a->parent = temp;
    a->left = temp->right;
    if (a->left != NULL)
    {
        a->left->parent = a;
    }
    temp->right = a;
    count_balance(a);
    count_balance(temp);
    return temp;
}
Node* TLR(Node* a)
{
    a->left = Tleft(a->left);
    return Tright(a);
}
Node* TRL(Node* a)
{
    a->right = Tright(a->right);
    return Tleft(a);
}
void adjust(Node* a)
{
    count_balance(a);
    if (a->balance == -2) {
        if (a->left->balance <= 0) {
            a = Tright(a);
        }
        else {
            a = TLR(a);
        }
    }
    else if (a->balance == 2) {
        if (a->right->balance >= 0) {
            a = Tleft(a);
        }
        else {
            a = TRL(a);
        }
    }
    if (a->parent) {
        adjust(a->parent);
    }
    else {
        AVL_TREE.head = a;
    }
}
void visit (Node* a)
{
    if (a == NULL)
        return;
    cout << a->val << " ";
    visit(a->left);
    visit(a->right);
    return;
}
void build(int val, Node* a)
{
    Node* node = find(val, a);
    if (node == 0) {
        AVL_TREE.head = new Node;
        AVL_TREE.head->val = val;
        AVL_TREE.head->left = AVL_TREE.head->right = 0;
        AVL_TREE.head->parent = 0;
        AVL_TREE.head->balance = 0;
    }
    else if (node->val != val) {
        if (node->val > val) {
            node->left = new Node;
            node->left->val = val;
            node->left->left = node->left->right = 0;
            node->left->parent = node;
            node->left->balance = 0;
            adjust(node);
        }
        else if (node->val < val) {
            node->right = (Node*)malloc(sizeof(Node));
            node->right->val = val;
            node->right->left = node->right->right = 0;
            node->right->parent = node;
            node->right->balance = 0;
            adjust(node);
        }
    }
}
int main()
{
    int num;
    cin >> num;
    for (int i(0); i < num; i++)
    {
        int temp;
        cin >> temp;
        build(temp, AVL_TREE.head);
    }
    visit(AVL_TREE.head);
    return 0;
}
/**************************************************************
    Problem: 1132
    User: 181860077
    Language: C++
    Result: 正确
    Time:20 ms
    Memory:1540 kb
****************************************************************/