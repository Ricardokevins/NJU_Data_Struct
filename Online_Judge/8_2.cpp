/*
问题 B: 守卫宝藏
时间限制: 1 Sec  内存限制: 10 MB
提交: 355  解决: 111
[提交][状态][讨论版]
题目描述
小蓝鲸们被派遣去守卫宝藏。宝藏分布呈一个二叉树，二叉树的每个节点都是一个藏宝的地点。一位小蓝鲸站在一个节点可以同时守卫这个节点和与这个节点直接相邻的所有节点。现在想知道至少要派遣多少位小蓝鲸才能守卫所有的宝藏。
输入
第一行，表示二叉树的前序遍历序列。
输入中的 0 表示有节点，输入中的 -1 表示空节点。（0≤二 叉 树 中 非 空 节 点 个 数≤500 ） 
输出
一行一个整数，表示至少需要的小蓝鲸的人数。
样例输入
0 0 0 -1 -1 0 -1 -1 0 -1 -1
样例输出
2
提示
*/

#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
};
 
int result = 0;
 
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
 
int dfs(Node* head) {
    if (head == NULL) return 0;
 
    int myleft = dfs(head->left);
    int myright = dfs(head->right);
 
    if (myleft + myright == 0)
        return 1;
    else if (myleft == 1 || myright == 1) {
        result++; return 2;
    }
    else
        return 0;
}
 
int minCamera(Node* root) {
 
    Node* dummyHead = new Node;
    dummyHead->left = root;
    dummyHead->right = NULL;
    dfs(dummyHead);
    return result;
}
 
 
int main()
{
    Node* head = build();
    cout << minCamera(head);
    return 0;
}
     
/**************************************************************
    Problem: 1196
    User: 181860077
    Language: C++
    Result: 正确
    Time:32 ms
    Memory:1536 kb
****************************************************************/