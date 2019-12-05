/*
问题 C: 最优规划
时间限制: 1 Sec  内存限制: 128 MB
提交: 699  解决: 96
[提交][状态][讨论版]
题目描述
风景秀丽人杰地灵的JS省，下辖编号1~n的n个城市。为了推动全省经济发展，JS省省长决定在各市之间修建高速公路。经过认真调研和实地考察，省长已经获取了所有m条架设高速公路的可行方案，第i条方案给出了在xi市和yi市之间架设高速公路的收支费用ci，这里的费用ci=架设道路的财力花费-道路建成后的收入（收费站收费或征收养路费），因而该费用的值可正可负。

值得一提的是，JS省内有一条穿省而过的江河，这就为JS省提供了发展水上运输的可能，在调研过程中，JS省的省长同样获取了在每个城市建设港口所需要的开销，这里用di表示在xi市建立港口的费用开销，且这一开销一定为正值。任何两个建立了港口的城市可以直接通过水道相连。

为了做到最优的统筹规划，JS省的省长希望通过有选择地架设高速公路和港口，使得省内任意两个城市可以通过这些新建的高速公路或港口互达，同时希望开销尽可能小（当然如果还能有盈余，则盈余越多越好）。于是省长只能向无所不能的小蓝鲸请教，希望他（或者说是你）能够帮忙计算出这一最小开销(甚至是最高盈余)。

注：本题允许使用sort库函数进行排序 。

输入
第1行输入两个整数n和m，空格隔开，分别表示JS省的城市数目以及架设高速公路的方案条数。1≤n≤10000，1≤m≤100000。

第2到m+1行，每行输入三个整数x，y，c，表示在城市x和y之间架设高速公路的收支费用c，1≤x, y≤N，-1000≤c≤1000。

第m+2行，一共n个整数，用空格隔开，表示在第i个城市修建港口的开销di，-1≤di≤1000，且di≠0，di=-1表示该城市不能修建港口。

输出
仅一行，包含一个整数，表示最小开销，如果还能够有盈余，则输出结果应该是一个负数，其绝对值表示最大盈余。
样例输入
5 6
1 2 7
1 3 5
1 4 4
1 5 8
2 3 6
4 5 10
-1 10 1 2 10
样例输出
21
提示
样例说明，最优规划方式是在1和4，2和3，1和5之间架设高速公路，在3和4城市建立港口，总开销为21。

[提交][状态]
*/

#include<iostream>
using namespace std;
const int INF =2147483647;
#define maxn  10050
 
bool used[maxn];
 
int  mincost[maxn] = { 0 };
int cost[maxn][maxn] = { 0 };
 
int prime(int n)
{
    for (int i = 0; i <= n; i++)
    {
        mincost[i] = INF;
        used[i] = false;
    }
 
    mincost[1] = 0;
    int res = 0;
 
    while (true)
    {
        int  v = -1;
        for (int u = 1; u <= n; u++)
        {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }
        if (v < 0)
            break;
        used[v] = true;
        res += mincost[v];
        for (int u = 1; u <= n; u++)
        {
            mincost[u] = mincost[u]< cost[v][u]? mincost[u]: cost[v][u];
        }
    }
    return res;
}
 
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
     
    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= n+1; j++)
        {
            cost[i][j] = INF;
        }
    }
 
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //cout << a << " " << b << " " << c << endl;
        cost[a][b] = c;
        cost[b][a] = c;
    }
 
    int result1 = prime(n);
     
    int ship[maxn] = { 0 };
 
    for (int i(0); i < n; i++)
    {
        cin >> ship[i];
    }
     
    for (int i(0); i < n + 1; i++)
    {
        if (ship[i] != -1)
        {
            cost[i+1][n + 1] = ship[i];
            cost[n + 1][i+1] = ship[i];
        }
    }
 
    int result2 = prime(n+1);
     
    if (result1 > result2)
    {
        cout << result2;
    }
    else
    {
        cout << result1;
    }
    return 0;
}
/**************************************************************
    Problem: 1198
    User: 181860077
    Language: C++
    Result: 运行错误
****************************************************************/