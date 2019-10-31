/*
问题 B: 镜像二叉树
时间限制: 1 Sec  内存限制: 128 MB
提交: 363  解决: 68
[提交][状态][讨论版]
题目描述
给定两个二叉树，检查它们是否呈镜像对称的。即树的结构成轴对称，且对应节点的节点值相同。
例如，下面两个二叉树是镜像对称的是对称的。（图1） 
    2               2
   / \              / \
  3   4          4   3
 / \                   / \
5   4                4   5

下面两个二叉数不是镜像对称（图2）
    1             1
   / \            / \
  2   3        2   3
   \    \         \    \
    5    5       5   5
输入
第一棵树的输入在第1行，表示二叉树的前序遍历序列
第二棵树的输入在第2行，表示二叉树的前序遍历序列
节点值的范围为[0,100]区间内的整数，输入中的-1表示空节点, 二叉树的节点数目(不包括空节点)为N满足0 ≤ N ≤ 200 

若其中一行为-1，则表示该树为空。 


输出
输出"YES"表示两颗二叉树对称，输出"NO"表示两棵树不对称。
样例输入
2 3 5 -1 -1 4 -1 -1 4 -1 -1
2 4 -1 -1 3 4 -1 -1 5 -1 -1
样例输出
YES
提示
样例输入对应图1二叉树。

[提交][状态]
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
};
vector<int>tree1;
vector<int>tree2;
vector<int>res1;
vector<int>res2;
int change_num(string a)
{
    int num(0);
    int flag(0);
    if (a.size() == 0)
        return num;
    if (a[0] == '-')
    {
        flag = 1;
        a.erase(a.begin());
    }
    while (a.size() != 0)
    {
        num = num * 10;
        num += a[0] - '0';
        a.erase(a.begin());
    }
    if (flag)
        num = -num;
    return num;
}
Node* build1(int &pos)
{
    if (pos > tree1.size())
    {
        return NULL;
    }
    if (tree1[pos] == -1)
    {
        pos += 1;
        return NULL;
    }
    Node* temp = new Node;
    temp->val = tree1[pos];
    pos += 1;
    temp->left = build1(pos );
    temp->right = build1(pos);
    return temp;
}
Node* build2(int& pos)
{
    if (pos > tree2.size())
    {
        return NULL;
    }
    if (tree2[pos] == -1)
    {
        pos += 1;
        return NULL;
    }
    Node* temp = new Node;
    temp->val = tree2[pos];
    pos += 1;
    temp->left = build2(pos);
    temp->right = build2(pos);
    return temp;
}
 
void visit1(Node* root)
{
    if (root == NULL)
    {
        res1.push_back(-1);
        return;
    }
    res1.push_back(root->val);
    visit1(root->left);
    visit1(root->right);
    return;
}
void visit2(Node* root)
{
    if (root == NULL)
    {
        res2.push_back(-1);
        return;
    }
    res2.push_back(root->val);
    visit2(root->right);
    visit2(root->left);
    return;
}
int main()
{
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    string temp;
    for (int i(0); i < a.size(); i++)
    {
        if (a[i] != ' ')
        {
            temp.push_back(a[i]);
        }
        else
        {
            if (temp.size() == 0)
            {
                continue;
            }
            else
            {
                int num(0);
                num = change_num(temp);
                tree1.push_back(num);
                temp.clear();
            }
        }
    }
    int num(0);
    num = change_num(temp);
    tree1.push_back(num);
    temp.clear();
    for (int i(0); i < b.size(); i++)
    {
        if (b[i] != ' ')
        {
            temp.push_back(b[i]);
        }
        else
        {
            if (temp.size() == 0)
            {
                continue;
            }
            else
            {
                int num(0);
                num = change_num(temp);
                tree2.push_back(num);
                temp.clear();
            }
        }
    }
    num = 0;
    num = change_num(temp);
    tree2.push_back(num);
    temp.clear();
    int pos1(0);
    int pos2(0);
    Node*Tree1=build1(pos1);
    Node* Tree2 = build2(pos2);
    visit1(Tree1);
    visit2(Tree2);
    if (res1.size() != res2.size())
    {
        cout << "NO";
        return 0;
    }
    for (int i(0); i < res1.size(); i++)
    {
        if (res1[i] != res2[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
/**************************************************************
    Problem: 1186
    User: 181860077
    Language: C++
    Result: 正确
    Time:36 ms
    Memory:1544 kb
****************************************************************/
