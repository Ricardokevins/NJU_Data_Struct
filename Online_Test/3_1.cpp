/*
问题 A: 小蓝鲸的鱼塘
时间限制: 1 Sec  内存限制: 10 MB
提交: 423  解决: 99
[提交][状态][讨论版]
题目描述
小蓝鲸的家乡有一个很大的池塘，池塘被分为m×n个小格子（东西方向m行，南北方向n列）。每个格子是一个鱼塘。为了提高产量，需要将部分鱼塘之间连通，从而合成一个新鱼塘。但是，鱼塘和鱼塘之间只能沿东西或南北方向连通。

现在我们已经知道哪些鱼塘之间已经连通，小蓝鲸想知道现在总共有多少个新鱼塘，于是向乐于助人的你寻求帮助。

输入
第一行：两个整数m，n，用空格分开，表示格子的行数、列数（1<m,n<1000）。

第二行：一个整数k，表示下面还有k行数据(0<k<100000)

下面k行：每行两个整数a、b，表示编号为a的鱼塘和编号为b的鱼塘连通了，a鱼塘和b鱼塘是相邻的，用空格隔开。

 

格子从上到下，从左到右编号。比如：5 * 4 的小格子，编号：

1 2 3 4

5 6 7 8

9 10 11 12

13 14 15 16

17 18 19 20

输出
一个整数，表示新鱼塘的数目。行末无多余空格、换行。

样例输入
5 4
16
2 3
1 5
5 9
4 8
7 8
9 10
10 11
11 12
10 14
12 16
14 18
17 18
15 19
19 20
9 13
13 17
样例输出
5
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
vector<int>my_data;
int myfind(int k)
{
    if (my_data[k] == k)
        return k;
    return my_data[k] = myfind(my_data[k]);
}
int  myunion(int a, int b)
{
    int a1 = myfind(a);
    int b1 = myfind(b);
    if (a1 != b1)
    {
        my_data[a1] = b1;
        return 1;
    }
    return 0;
}
int main()
{
    int m(0);
    int n(0);
    cin >> m;
    cin >> n;
    int total = n * m;
    for (int i(0); i < m * n; i++)
    {
        my_data.push_back(i);
    }
    int num;
    cin >> num;
    for (int i(0); i < num; i++)
    {
        int x;
        int y;
        cin >> x;
        cin >> y;     
        total-=myunion(x-1, y-1);
    }
    cout << total;
    return 0;
}
/**************************************************************
    Problem: 1200
    User: 181860077
    Language: C++
    Result: 正确
    Time:124 ms
    Memory:7684 kb
****************************************************************/