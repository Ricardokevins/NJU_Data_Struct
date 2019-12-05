/*
问题 A: 螺旋矩阵
时间限制: 1 Sec  内存限制: 128 MB
提交: 351  解决: 98
[提交][状态][讨论版]
题目描述
给定一个包含m × n个元素的矩阵（m行，n列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
输入
第一行：矩阵的行数，

第二行：矩阵的列数。（1≤m≤100，1≤n≤100）

第三行：矩阵的第一行，每个元素之间用空格隔开

第四行：矩阵的第二行 ，每个元素之间用空格隔开

以此类推

输出
顺时针螺旋顺序返回的元素，每个元素之间用空格隔开，包括行尾的空格。
样例输入
3
3
1 2 3
4 5 6
7 8 9
样例输出
1 2 3 6 9 8 7 4 5 
提示
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int m(0);
    while (cin >> m)
    {
        int n(0);
        cin >> n;
        vector<vector<int>>num;
        for (int i(0); i < m; i++)
        {
            vector<int>temp;
            for (int j(0); j < n; j++)
            {
                int a(0);
                cin >> a;
                temp.push_back(a);
            }
            num.push_back(temp);
        }
        int count(0);
        while (1)
        {
            if (m - count * 2 > 0 && n - count * 2 > 0)
            {
                if (m - count * 2 == 1 && n - count * 2 == 1)
                {
                    cout << num[count][count] << " ";
                    cout << endl;
                    break;
                }
                if (m - count * 2 == 1 )
                {
                    for (int i(count); i < n - count; i++)
                    {
                        cout << num[count][i] << " ";
                    }
                    cout << endl;
                    break;
                }
                if (n - count * 2 == 1)
                {
                    for (int i(count); i < m - count ; i++)
                    {
                        cout << num[i][n - count - 1] << " ";
                    }
                    cout << endl;
                    break;
                }
                for (int i(count); i < n - count; i++)
                {
                    cout << num[count][i] << " ";
                }
                for (int i(count + 1); i < m - count - 1; i++)
                {
                    cout << num[i][n - count - 1] << " ";
                }
                for (int i(n - count-1); i >= count; i--)
                {
                    cout << num[m - count - 1][i] << " ";
                }
                for (int i(m - count - 2); i > count; i--)
                {
                    cout << num[i][count] << " ";
                }
                count++;
            }
            else
            {
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1170
    User: 181860077
    Language: C++
    Result: 正确
    Time:72 ms
    Memory:1548 kb
****************************************************************/