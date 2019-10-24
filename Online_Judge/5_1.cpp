/*
问题 A: 字符串匹配
时间限制: 1 Sec  内存限制: 128 MB
提交: 867  解决: 95
[提交][状态][讨论版]
题目描述
现有两个字符串S和W，要求在S中找到跟W匹配的子串，并依次输出匹配的子串的起始下标（从零开始）。如果没有匹配的子串，则输出false。

输入
输入数据包括两行，第一行为字符串S，第二行为字符串W。字符串长度满足1≤len(W)≤len(S)≤100000。

输出
输出仅一行，为所有匹配位置的起始坐标，若没有找到匹配的起始点，则输出false。

样例输入
abc abcdab abcdabcdabde
abcd
样例输出
4 11 15
提示

使用KMP算法


注意：如果使用std::getline(cin, str)获取输入，str包含‘\n’。即abcdabd的size为8。
*/
#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
#define maxsize 101000
int mynext[maxsize];
void get_next(string a)
{
    memset(mynext, -1, maxsize);
    for (int i(1); i <= a.size();i++)
    {
        int pos =mynext[i - 1];
        while (pos != -1 && a[i-1] != a[pos])
        {
            pos = mynext[pos];
        }
        mynext[i] = pos + 1;
    }
    return;
}
 
bool KMP_find(string a, string b)
{
    get_next(b);
    int pos = 0;
    int count=0;
    int result[maxsize] = { 0 };
    for (int i(0); i < a.size()-1;)
    {
        while (pos != -1&&(pos==(b.size()) || b[pos] != a[i]))
        {
            pos = mynext[pos];
        }
        pos++;
        i++;
        if (pos == b.size())
        {
            result[count]=(i - pos);
            count++;
        }
    }
    if (count == 0)
    {
        cout << "false" << endl;
        return false;
    }
    for (int i(0); i < count; i++)
    {
        cout << result[i] << " ";
    }
    return true;
 
}
 
int main()
{
    string a;
    string b;
 
    getline(cin, a);
    cin>>b;
    KMP_find(a, b);
    return 0;
 
}
