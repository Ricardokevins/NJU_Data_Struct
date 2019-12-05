/*
问题 B: 叠罗汉
时间限制: 1 Sec  内存限制: 10 MB
提交: 456  解决: 86
[提交][状态][讨论版]
题目描述
在叠罗汉表演中，若演员A的身高和体重都小于演员B的身高和体重，那么演员A就可以位于演员B的上方。现在有N名演员，小蓝鲸想知道叠罗汉的高度最高是多少？

输入
第一行：N，表示演员的数量（1 ≤ N ≤ 10000）

第二行~第N+1行：两个正整数，表示每个演员的身高和体重，用空格隔开。

输出
一个整数，表示叠罗汉的最大高度。

样例输入
4
5 4
6 4
6 7
2 3
样例输出
3
提示
[提交][状态]
*/

#include<iostream>
#include<vector>
using namespace std;
struct people {
    int height;
    int weight;
};
int main()
{
    vector<people>mydata;
    int num(0);
    cin >> num;
    if (num == 0)
        return 0;
    for (int i(0); i < num; i++)
    {
        people temp;
        cin >> temp.height;
        cin >> temp.weight;
        mydata.push_back(temp);
    }
    for (int i(0); i < mydata.size(); i++)
    {
        int pos = i;
        for (int j(i); j < mydata.size(); j++)
        {
            if (mydata[j].height > mydata[pos].height)
            {
                pos = j;
            }
            else
            {
                if (mydata[j].height == mydata[pos].height && mydata[j].weight > mydata[pos].weight)
                {
                    pos = j;
                }
            }
        }
        people temp1;
        temp1 = mydata[i];
        mydata[i] = mydata[pos];
        mydata[pos] = temp1;
    }

 
    if (mydata.size() <= 1)
        return mydata.size();
    int result = -1;
    vector<int>dp(num, 1);
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (mydata[i].weight < mydata[j].weight&&mydata[i].height < mydata[j].height)
            {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
        if (result < dp[i])
        {
            result = dp[i];
        }
 
    }
 
    cout << result << endl;
    return 0;
 
}
/**************************************************************
    Problem: 1194
    User: 181860077
    Language: C++
    Result: 正确
    Time:1960 ms
    Memory:1676 kb
****************************************************************/