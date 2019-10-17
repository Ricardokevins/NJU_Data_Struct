/*
问题 B: linux路径
时间限制: 1 Sec  内存限制: 10 MB
提交: 118  解决: 33
[提交][状态][讨论版]
题目描述
给定linux系统的一个绝对路径，现在我们需要把它简化为规范路径，规范路径是表示绝对路径的最短字符串。 

在linux系统中，绝对路径是指从根目录开始的最终指向一个文件或者目录的路径。在linux系统中，`/`表示根目录，也就是说绝对路径是以`/`开始的一条路径，比如说`/home/foo`。 

假设路径中的字符只包含大小写英文字母，`/`和`.`，不包含其他字符。 

`/`放在路径开头表示根目录，放在路径中间表示下一级目录，连续的多个`/`和一个`/`表示相同的意思。我们需要去掉路径中连续多个`/`，只保留一个`/`，同时最后一个目录名（如果存在）不能以`/`结尾。例如，`/home//foo/`需要简化为`/home/foo`。 

此外，`.`表示当前目录本身；两个点`..`表示将目录切换到上一级目录；在目录简化的过程中，我们需要去掉路径中的`.`和`..`。例如`/.././`需要简化为`/`（根目录的上一级目录还是根目录）。需要注意的是，`.`可以和英文字母一起组成一个文件名/目录名，`.a`,`a.a`,`a.`都是合法的文件名/目录名。 

在linux中，以"."开头的文件/目录是一个隐藏文件/目录，例如‘/.a’。


输入
一个字符串，表示绝对路径（1≤ 输入路径长度 ≤ 200） 

输出
一个字符串，表示简化后的绝对路径 

样例输入
/a/./b/../../c/
样例输出
/c
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    a.push_back('/');
    vector<string>word;
    string temp;
    int flag1 = 0;
    for (int i(0); i < a.size(); i++)
    {
        if (a[i] == '/')
        {
            if (flag1 == 0)
            {
                flag1 = 1;
                continue;
            }
            else
            {
                if (temp.size() == 0)
                {
                    continue;
                }
                else
                {
                    word.push_back(temp);
                    temp = "";
                    continue;
                }
            }
        }
        else
        {
            temp.push_back(a[i]);
        }
    }
    vector<string>result;
    for (int i(0); i < word.size(); i++)
    {
        if (word[i] == ".")
        {
            continue;
        }
        if (word[i] == "..")
        {
            if (result.size() != 0)
            {
                result.pop_back();
            }
        }
        else
        {
            result.push_back(word[i]);
        }
    }
    if (result.size() == 0)
    {
        cout << "/" << endl;
        return 0;
    }
    for (int i(0); i < result.size(); i++)
    {
        cout << "/" << result[i];
    }
    cout << endl;
    return 0;
}
/**************************************************************
    Problem: 1178
    User: 181860077
    Language: C++
    Result: 正确
    Time:52 ms
    Memory:1540 kb
****************************************************************/
