/*
问题 A: 食堂人数
时间限制: 1 Sec  内存限制: 10 MB
提交: 409  解决: 92
[提交][状态][讨论版]
题目描述
小蓝鲸所在的大学有四个食堂A、B、C、D，每个食堂吃饭的人数都有N种可能，聪明的小蓝鲸想知道有多少种组合情况，可以使得四个食堂的总人数刚好是10000。

输入
第一行：N（0 ≤ N ≤ 500）

第二行~第五行，每行有N个正整数，正整数之间用空格隔开。（正整数在int范围内）

输出
一个整数，表示可能的组合个数。若没有情况满足，则输出0。

样例输入
2
1000 2000
3000 2000
2000 3000
1000 3000
样例输出
3
提示
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int num(0);
    cin >> num;
    int result1[100000] = { 0 };
    int result2[100000] = { 0 };
    vector<vector<int>>mydata;
    for (int i(0); i < 4; i++)
    {
        vector<int>temp;
        for (int j(0); j < num; j++)
        {
            int kk;
            cin >> kk;
            temp.push_back(kk);
        }
        mydata.push_back(temp);
    }
    for (int i(0); i < num; i++)
    {
        for (int j(0); j < num; j++)
        {
            result1[mydata[0][i] + mydata[1][j]-1]++;
            result2[mydata[2][i] + mydata[3][j]-1]++;
        }
    }
    int hhh = 0;
    for (int i(0); i < 10000; i++)
    {
        if (result1[i] != 0)
        {
            int numbers = result1[i]*result2[9998 - i];
            hhh += numbers;
        }
    }
     
    cout << hhh;
    return 0;
}
/**************************************************************
    Problem: 1193
    User: 181860077
    Language: C++
    Result: 正确
    Time:60 ms
    Memory:2208 kb
****************************************************************/