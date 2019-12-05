/*
问题 D: 愉悦的小蓝鲸
时间限制: 1 Sec  内存限制: 32 MB
提交: 272  解决: 41
[提交][状态][讨论版]
题目描述
每天中午，⻝堂都会排起⻓⻓的队伍。队伍中的同学看到排在⾃⼰前⾯的⼈，⼼⾥会⼗分愉悦。因为他会想：前⾯⼏个⼈买完就轮到我买饭了。每个⼈的愉悦值定义为：他能看到的前⾯的⼈的个数。同学们的视线会被⽐⾃⼰⾼的⼈挡住，但不会被和⾃⼰⼀样⾼或者⽐⾃⼰矮的⼈挡住。

 

在队伍⼀旁的小蓝鲸被他们感染，⾃⼰也变得愉悦了。好奇的她想知道：这条队伍⾥所有⼈的愉悦值之和是多少？

 

你想帮助小蓝鲸解答，但是你很忙，所以你决定在 O（队 伍 的 ⼈ 数） 的时间内算出答案。 

输入
２⾏。
第1行1个正整数 n，表⽰队伍的⼈数。
第2行是n个正整数hi ，代表队伍中每个⼈的身高，⽤⼀个空格分隔。 第一个数字代表第一个同学，第二个数字代表第二个同学，以此类推。

（1≤n≤106，1≤hi≤109）

 

输出
输出队伍中所有⼈的愉悦值的和 。
样例输入
4
3 5 1 1
样例输出
4
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
        vector<int>mystack1;
        vector<int>num;
        vector<int>mystack2;
        int res(0);
        for (int i(0); i < m; i++)
        {
            int temp(0);
            cin >> temp;
            if (mystack1.size() == 0)
            {
                mystack1.push_back(temp);
                mystack2.push_back(i);
            }
            else
            {
 
                    while (mystack1.size() > 0 && temp >= mystack1[mystack1.size() - 1])
                    {
                        if (mystack1.size() <= 1)
                        {
                            res += mystack2[0];
                            mystack1.pop_back();
                            mystack2.pop_back();
                        }
                        else
                        {
                            res += mystack2[mystack2.size() - 1] - mystack2[mystack2.size() - 2];
                            //cout << res << endl;
                            mystack1.pop_back();
                            mystack2.pop_back();
                        }
                    }
                    mystack1.push_back(temp);
                    mystack2.push_back(i);
                 
            }
        }
        if (mystack1.size() > 0)
        {
            while (mystack1.size() > 0)
            {
                if (mystack1.size() <= 1)
                {
                    res += mystack2[0];
                    mystack1.pop_back();
                    mystack2.pop_back();
                }
                else
                {
                    res += mystack2[mystack2.size() - 1] - mystack2[mystack2.size() - 2];
                    //cout << res << endl;
                    mystack1.pop_back();
                    mystack2.pop_back();
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
/**************************************************************
    Problem: 1172
    User: 181860077
    Language: C++
    Result: 答案错误
****************************************************************/