/*
问题 A: 小蓝鲸的搜索树
时间限制: 1 Sec  内存限制: 10 MB
提交: 403  解决: 116
[提交][状态][讨论版]
题目描述
小蓝鲸在学习二叉搜索树，他完成作业时根据题目要求构建出了二叉搜索树，但小蓝鲸室友趁小蓝鲸不注意修改了小蓝鲸的搜索树：将其中的两个节点交换了位置，小蓝鲸想请你帮助他找出这两个交换的节点，并恢复二叉搜索树。
输入
第一行输入数字N ，表示二叉搜索树的节点个数（不包含空节点，总结点数为 2N+1）。（1≤N≤1.5×105）
第二行输入 2N+1个数字，二叉搜索树的前序表示，空节点用 -1 表示，没有相同节点。
输出
交换的两个节点数值，从小到大排列
样例输入
3
1 3 -1 2 -1 -1 -1
样例输出
1 3
提示
[提交][状态]
*/
#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
};
vector<int>data1;
vector<int>data2;
 
Node* build()
{
    int temp_data;
    cin >> temp_data;
    if (temp_data == -1)
        return NULL;
    Node* cur = new Node;
    cur->left = build();
    cur->right = build();
    cur->val = temp_data;
    return cur;
}
 
void visit(Node *head)
{
    if (head == NULL)
        return;
    visit(head->left);
    data1.push_back(head->val);
    visit(head->right);
    return;
}
 
int main()
{
    int num;
    cin >> num;
    Node* head = build();
    visit(head);
    int result1 = 0;
    int result2 = 0;
    int pos = 0;
    for (int i(0); i < data1.size()-1; i++)
    {
        if (data1[i] > data1[i + 1])
        {
            result1 = data1[i];
            pos = i + 1;
            break;
        }
    }
    for (int j = pos;j < data1.size(); j++)
    {
        if (data1[j] < data1[pos])
        {
            pos = j;
        }
    }
    result2 = data1[pos];
    cout << result2 << " " << result1 << endl;
 
}
/**************************************************************
    Problem: 1195
    User: 181860077
    Language: C++
    Result: 正确
    Time:960 ms
    Memory:5420 kb
****************************************************************/