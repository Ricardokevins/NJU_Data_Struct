/*
问题 C: 跳方格
时间限制: 1 Sec  内存限制: 128 MB
提交: 251  解决: 39
[提交][状态][讨论版]
题目描述
小蓝鲸最近下载了一款NJU版跳方格游戏。游戏规则如下：给定一个n×n的方格阵M，玩家需要从左上角移动到右下角，规定每次只能向右或者向下跳一格，方格阵M中每个数字代表经过此点消耗的体力，只有消耗的体力值较少，才能获得更高的游戏排名。小蓝鲸希望你能帮他计算出最小的体力消耗值。



输入
输入包括n+1行，第一行一个正整数n，(n≤50)，表示方格阵的规格。

第2到n+1行，每行n个整数，用空格隔开，代表经过该方格时消耗的体力值。

输出
输出仅一个整数，表示最小的体力消耗值。行末无多余空格换行符。
样例输入
4
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
样例输出
12
提示
1->3->1->0->6->1->0是体力消耗最少的方式。

[提交][状态]
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>mydata;
int min(-1);
int nums(0);
 
 
int count_bian()
{
    for (int i(nums - 2); i >= 0; i--)
    {
        mydata[nums - 1][i] += mydata[nums - 1][i + 1];
    }
    for (int i(nums - 2); i >= 0; i--)
    {
        mydata[i][nums-1] += mydata[i+1][nums-1];
    }
     
    for (int i(nums - 2); i >= 0; i--)
    {
        for (int j(nums - 2); j >= 0; j--)
        {
            mydata[j][i] += mydata[j + 1][i] > mydata[j][i + 1] ? mydata[j][i + 1] : mydata[j + 1][i];
        }
    }
    return 0;
}
int main()
{
     
     
    cin >> nums;
    for (int i(0); i < nums; i++)
    {
        vector<int>temp;
        for (int j(0); j < nums; j++)
        {
            int hh(0);
            cin >> hh;
            temp.push_back(hh);
        }
        mydata.push_back(temp);
    }
    count_bian();
    cout << mydata[0][0];
    return 0;
 
}
/**************************************************************
    Problem: 1184
    User: 181860077
    Language: C++
    Result: 正确
    Time:32 ms
    Memory:1548 kb
****************************************************************/
