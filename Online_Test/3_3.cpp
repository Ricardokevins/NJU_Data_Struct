/*
问题 C: 合并校区
时间限制: 1 Sec  内存限制: 128 MB
提交: 118  解决: 26
[提交][状态][讨论版]
题目描述
蓝鲸大学有两个校区A和B，现在想建一座天桥连通两个校区，小蓝鲸想知道这座天桥建在哪里可以使得天桥的长度最短。

现在使用一个M×N的矩阵模拟地图，1表示校区的覆盖范围，0表示不在校区的覆盖范围，输入保证两个校区是分开的，且每个校区内部都是连通的。

天桥需要建立在0的位置上，即把0变成1，通过翻转0，使得所有的1都连通起来，翻转的0的数目定义为天桥的长度。要求计算计算天桥的最短长度，即最少要翻转的0的数目。

输入
第一行两个 int 型数，代表地图的长M和宽N，0≤M,N≤200。 

之后有M行输入，每行有N个数，每个数取值为0或1。

输出
天桥的最短长度，一个 int 型数。
样例输入
4 4
1 1 0 0
0 0 0 0
0 0 1 1
0 0 1 1
样例输出
2
提示
[提交][状态]
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int total[40000] = { 0 };
 
int myfind(int k)
{
    if (total[k] == k)
        return k;
    return total[k] = myfind(total[k]);
}
int  myunion(int a, int b)
{
    int a1 = myfind(a);
    int b1 = myfind(b);
    if (a1 != b1)
    {
        //cout << "union " << a1 << " " << b1 << endl;
        total[a1] = b1;
        return 1;
    }
    return 0;
}
 
int main()
{
    vector<vector<int>>my_data;
    int m;
    int n;
    cin >> m;
    cin >> n;
    vector<int>temp2;
    for (int i(0); i < m+2; i++)
    {
        temp2.push_back(0);
    }
    my_data.push_back(temp2);
    for (int i(0); i < n; i++)
    {
        vector<int>temp;
        temp.push_back(0);
        for (int j(0); j < m; j++)
        {
            int temp_data;
            cin >> temp_data;
            temp.push_back(temp_data);
        }
        temp.push_back(0);
        my_data.push_back(temp);
    }
    my_data.push_back(temp2);
    for (int i(0); i < (m+2) *( n+2); i++)
    {
        total[i] = i;
    }
    for (int i(0); i < n + 2; i++)
    {
        for (int j(0); j < m + 2; j++)
        {
            //cout << my_data[i][j] << " ";
        }
        //cout << endl;
    }
    for (int i(0); i < n+2; i++)
    {
        for (int j(0); j < m+2; j++)
        {
 
            if (my_data[i][j] == 1)
            {
 
                if (my_data[i - 1][j] == 1)
                {
                    int id1 = i * (m+2) + j;
                    int id2 = id1 - (m + 2);
                    //cout << i << " " << j << endl;
                    myunion(id1, id2);
                }
 
                if (my_data[i + 1][j] == 1)
                {
                    int id1 = i * (m + 2) + j;
                    int id2 = id1 + (m + 2);
                    //cout << i << " " << j << endl;
                    myunion(id1, id2);
                }
 
                if (my_data[i][j - 1] == 1)
                {
                    int id1 = i * (m + 2) + j;
                    int id2 = id1 - 1;
                    //cout << i << " " << j << endl;
                    myunion(id1, id2);
                }
 
 
                if (my_data[i][j + 1] == 1)
                {
                    int id1 = i * (m + 2) + j;
                    int id2 = id1 + 1;
                    //cout << i << " " << j << endl;
                    myunion(id1, id2);
                }
 
            }
        }
    }
    vector<int>a_x;
    vector<int>a_y;
    vector<int>b_x;
    vector<int>b_y;
    for (int i(0); i < n+2; i++)
    {
        for (int j(0); j < m+2; j++)
        {
            //cout<<i* (m + 2) + j<<" ";
            if (my_data[i][j] == 1)
            {
                if (my_data[i - 1][j] == 0 || my_data[i + 1][j] == 0 || my_data[i][j + 1] == 0 || my_data[i][j - 1] == 0)
                {
                    if (a_x.size() == 0)
                    {
                        a_x.push_back(i);
                        a_y.push_back(j);
                    }
                    else
                    {
                        int id_3 = a_x[0] * (m+2) + a_y[0];
                        int id_4 = i * (m+2) + j;
                        if (myfind(id_3) == myfind(id_4))
                        {
                            a_x.push_back(i);
                            a_y.push_back(j);
                        }
                        else
                        {
                            b_x.push_back(i);
                            b_y.push_back(j);
                        }
                    }
                }
            }
        }
        //cout << endl;
    }
    /*
    for (int i(0); i < a_x.size(); i++)
    {
        cout << a_x[i] << " " << a_y[i] << endl;
    }
    cout << endl;
    for (int i(0); i < b_x.size(); i++)
    {
        cout << b_x[i] << " " << b_y[i] << endl;
    }
    */
 
    int min_di = 100000;
 
    for (int i(0); i < a_x.size(); i++)
    {
        for (int j(0); j < b_x.size(); j++)
        {
            int temp_dis = 0;
            int x_dis = a_x[i] - b_x[j];
            int y_dis = a_y[i] - b_y[j];
            if (x_dis < 0)
            {
                temp_dis -= x_dis;
            }
            else
            {
                temp_dis += x_dis;
            }
            if (y_dis < 0)
            {
                temp_dis -= y_dis;
            }
            else
            {
                temp_dis += y_dis;
            }
            if (temp_dis < min_di)
            {
                min_di = temp_dis;
            }
        }
         
    }
    cout << min_di-1 << endl;
    return 0;
}
/**************************************************************
    Problem: 1201
    User: 181860077
    Language: C++
    Result: 正确
    Time:52 ms
    Memory:1696 kb
****************************************************************/