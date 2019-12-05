/*
问题 B: 数字序列还原
时间限制: 1 Sec  内存限制: 128 MB
提交: 286  解决: 42
[提交][状态][讨论版]
题目描述
小蓝鲸在编辑一组由1到m共m个连续数字组成的乱序序列（每个数字仅出现一次），每两个相邻数字之间用空格隔开。由于编辑上的粗心，小蓝鲸误将所有的空格都删掉了，整个数字序列变成了一个没有空格的数字串。请编写程序，帮助小蓝鲸将数字串还原成原来的数字序列。
输入
一串由1到m中所有数字无间隔拼接在一起的数字串，其中0<m≤50。
输出
还原后的数字序列，相邻两个数字之间用空格隔开（行末无多余空格）。本题测试数据保证解的唯一性。

样例输入
111221496710358
样例输出
11 12 2 1 4 9 6 7 10 3 5 8
提示
[提交][状态]
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
 
int max_num(0);
int length = 0;
int change_num(string a)
{
    int num(0);
    int flag(0);
    if (a.size() == 0)
        return num;
    if (a[0] == '-')
    {
        flag = 1;
        a.erase(a.begin());
    }
    while (a.size() != 0)
    {
        num = num * 10;
        num += a[0] - '0';
        a.erase(a.begin());
    }
    if (flag)
        num = -num;
    return num;
}
vector<int> divide(vector<int> a,string b,int pos)
{
    if (pos>=length)
        return a;
    if (pos==length-1)
    {
        int temp_data =b[pos]-'0';
        if (temp_data > max_num)
            return a;
        for (int i(0); i < a.size(); i++)
        {
            if (a[i] == temp_data)
            {
                return a;
            }
        }
 
             
        a.push_back(temp_data);
        return a;
         
    }
    vector<int>try1 = a;
    vector<int>try2 = a;
    int temp_data = b[pos] - '0';
    if (temp_data <= max_num&& temp_data!=0)
    {
        int flag = 0;
        for (int i(0); i < try1.size(); i++)
        {
            if (try1[i] == temp_data)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            try1.push_back(temp_data);
            try1=divide(try1, b, pos + 1);
            if (try1.size() == max_num )
            {
                return try1;
            }
        }
    }
    string hhh;
    hhh.push_back(b[pos]);
    hhh.push_back(b[pos + 1]);
    int h_data = change_num(hhh);
    if (h_data <= max_num&&b[pos] != '0')
    {
        int flag = 0;
        for (int i(0); i < a.size(); i++)
        {
            if (try2[i] == h_data)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            try2.push_back(h_data);
            try2=divide(try2, b, pos + 2);
            if (try2.size() == max_num)
            {
                return try2;
            }
        }
    }
    return a;
}
int main()
{
    string a;
    cin >> a;
    length = a.size();
     
    if (length < 10)
    {
        max_num = length;
    }
    else
    {
        length -= 9;
        max_num += length / 2 + 9;
    }
    length += 9;
    //cout << max_num;
    vector<int>result;
    result= divide(result, a, 0);
    for (int i(0); i < result.size(); i++)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1169
    User: 181860077
    Language: C++
    Result: 正确
    Time:40 ms
    Memory:1540 kb
****************************************************************/