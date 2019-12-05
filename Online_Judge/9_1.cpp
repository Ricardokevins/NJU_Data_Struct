/*
问题 A: AVL树构建
时间限制: 1 Sec  内存限制: 128 MB
提交: 562  解决: 309
[提交][状态][讨论版]
题目描述
给定包含n个元素的数组A，从前往后依次遍历A中每个元素，逐步构建一颗AVL树（每插入一个节点，如果造成不平衡，进行单旋或双旋操作）。输出最终AVL树的前序遍历，结果以空格隔开。

输入
两行数据，第一行为n，1≤n≤20，第二行为数组A，以空格隔开。 

输出
最终AVL树的前序遍历结果。

样例输入
9
16 3 7 11 9 26 18 14 15
样例输出
11 7 3 9 18 15 14 16 26
提示
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> ans;
    vector<int> degree; 
    vector< vector<int> > Graph(n, vector<int>());
    queue<int> Q; 
    for (int i(0); i < n; i++)
    {
        degree.push_back(0);
    }
    for (int i(0); i < m; i++)
    {
        int temp1;
        int temp2;
        cin >> temp1;
        cin >> temp2;
        Graph[temp1].push_back(temp2);
        Graph[temp2].push_back(temp1);
        degree[temp1]++;
        degree[temp2]++;
    }
    for (int i = 0; i < n; i++)
        if (degree[i] == 1)
            Q.push(i);
    int rst = n;
     
    if (rst == 1)
        return 0;
 
     
    while (rst != 1 && rst != 2)
    {
        int len = Q.size();
        rst -= len;
        for (int i = 0; i < len; i++)
        {
            int cur = Q.front(); Q.pop();
            for (auto v : Graph[cur])
            {
                if (degree[v] > 0)
                    degree[v]--;
                if (degree[v] == 1)
                    Q.push(v);
            }
        }
    }
     
    while (!Q.empty())
    {
        ans.push_back(Q.front());
        Q.pop();
    }
 
    sort(ans.begin(), ans.end());
    for (int i(0); i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
/**************************************************************
    Problem: 1199
    User: 181860077
    Language: C++
    Result: 正确
    Time:112 ms
    Memory:3048 kb
****************************************************************/