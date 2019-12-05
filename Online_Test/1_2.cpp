/*
问题 B: 火车调度
时间限制: 1 Sec  内存限制: 10 MB
提交: 455  解决: 73
[提交][状态][讨论版]
题目描述
仙林⽕⻋站有⼀个调度站，其形式如图所示：



现在有 N列⽕⻋从⻄向东开，按照到达⻋站的先后次序编号为 0到N-1 。根据调度要求，⽕⻋需要在仙林站内进⾏调度，改变驶出⻋站的顺序。为了实现这⼀⽬的，调度站可以针对各列⽕⻋执⾏以下操作：
+ 若调度站还有空间，则可以令下⼀列⽕⻋进⼊调度站
+ 若调度站内有⽕⻋，则可以令调度站内最先到达的⽕⻋驶出调度站
+ 可以令下⼀列⽕⻋不经过调度站，直接驶离仙林站
不过由于仙林⻋站较⼩，调度站内只能容纳 M列⽕⻋，请你帮忙确认⽕⻋顺序调度在仙林站内是否可以完成。 
 

输入
第⼀⾏有两个数字N 和 M，⽤空格隔开，分别表示⽕⻋总数以及调度站容纳的⽕⻋数⽬。第⼆⾏有N个数字，他们都在0 到 N-1间，且不重复，⽤空格隔开，表示⽕⻋驶离仙林站的顺序。

1 ≤ N ≤ 1000， 1 ≤ M ≤ 100 
 

输出
如果能够调度成功，回答YES，否则回答NO。输出请⽤⼤写。 
样例输入
4 2
2 0 1 3
样例输出
YES
提示
[提交][状态]
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m(0);
    while (cin >> m)
    {
        int n(0);
        cin >> n;
        vector<int>car;
        for (int i(0); i < m; i++)
        {
            int temp(0);
            cin >> temp;
            car.push_back(temp);
        }
        vector<int>station;
        int cur(0);
        int mymaxsize=0;
        int i(0);
        for (; i < car.size()&&cur<m;)
        {
            if (station.size() != 0)
            {
                if (car[i] == station[0])
                {
                    station.erase(station.begin());
                    i++;
                }
                else
                {
                    if (car[i] == cur)
                    {
                        i++;
                        cur++;
                    }
                    else
                    {
                        station.push_back(cur);
                        if (mymaxsize < station.size())
                        {
                            mymaxsize = station.size();
                        }
                        cur++;
                    }
                }
            }
            else
            {
                if (car[i] == cur)
                {
                    i++;
                    cur++;
                }
                else
                {
                    station.push_back(cur);
                    if (mymaxsize < station.size())
                    {
                        mymaxsize = station.size();
                    }
                    cur++;
                }
            }
        }
        if (i == car.size())
        {
            if (mymaxsize > n)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {       
            while (i < car.size() && station.size()>0)
            {
                if (car[i] == station[0])
                {
                    i++;
                    station.erase(station.begin());
                }
                else
                {
                    break;
                }
            }
            if (i == car.size())
            {
                if (mymaxsize > n)
                {
                    cout << "NO" << endl;
                }
                else
                {
                    cout << "YES" << endl;
                }
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1171
    User: 181860077
    Language: C++
    Result: 正确
    Time:40 ms
    Memory:1544 kb
****************************************************************/