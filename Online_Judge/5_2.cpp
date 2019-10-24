/*
问题 B: 寻找小蓝鲸的堂兄弟
时间限制: 1 Sec  内存限制: 10 MB
提交: 275  解决: 33
[提交][状态][讨论版]
题目描述
在二叉树家族中，定义“堂兄弟”如下：如果两个节点的深度相同，但是父节点不同，则它们是一对堂兄弟。现有一个二叉树家族，其中每一个节点的值都不同。输入小蓝鲸的节点值x和一位家族成员的节点值y，判断这位家族成员是否为小蓝鲸的堂兄弟。

 

注意：本题需要使用二叉树数据结构完成。

输入
第一行：二叉树节点值的顺序表示，用空格隔开。若为空节点，则为‘#’。1≤节点数≤100

例：

（1）



1 2 3 4

（2）



1 2 3 # 4 # 5

第二行：小蓝鲸的节点值。

第三行：家族成员的节点值。

输出
true或false。true表示该家族成员是小蓝鲸的堂兄弟，false表示该家族成员不是小蓝鲸的堂兄弟。行末无多余空格换行符。

样例输入
1 2 3 4
4
3
样例输出
false
提示
*/
#include<iostream>
#include<string>
using namespace std;
#define maxsize 100000
int depth(int i)
{
    int d(0);
    int count(2);
    while (1)
    {
        if ((count-1) >= (i+1))
            break;
        d++;
        count = count * 2;
    }
    return d;
}
int main()
{
    string a;
    getline(cin, a);
    int b[maxsize] = {};
    string temp;
    int pos = 0;
    for (int i(0); i < a.size(); i++)
    {
        if (a[i] == '#')
        {
            b[pos] = -1;
            pos++;
            continue;
        }
        if (a[i] != ' ')
        {
            temp.push_back(a[i]);
        }
        else
        {
            if (temp.size() == 0)
            {
                continue;
            }
            else
            {
                int num(0);
                num = stoi(temp);
                b[pos] = num;
                temp.clear();
                pos++;
            }
        }
 
    }
    if (temp.size() != 0)
    {
        int num(0);
        num = stoi(temp);
        b[pos] = num;
        temp.clear();
        pos++;
    }
    int a1(0);
    cin >> a1;
    int a2(0);
    cin >> a2;
     
    int pos_1(0);
    int pos_2(0);
    for (int i(0); i < pos; i++)
    {
        if (b[i] == a1)
            pos_1 = i;
        if (b[i] == a2)
            pos_2 = i;
    }
    int fat_1(0);
    int fat_2(0);
    fat_1 = (pos_1 - 1) / 2;
    fat_2 = (pos_2 - 1) / 2;
    int res_1 = depth(pos_1);
    int res_2 = depth(pos_2);
    int res_3 = depth(fat_1);
    int res_4 = depth(fat_2);
    //cout << "pos_1  " << pos_1 << "  pos_2  " << pos_2 << endl;
    //cout << "fat_1  " << fat_1 << "  fat_2  " << fat_2 << endl;
    //cout << res_1 << "  " << res_2 << "   " << res_3 << "  " << res_4 << endl;
    //return 0;
    if (fat_1 == fat_2)
    {
        cout<<"false";
        return 0;
    }
    if (res_1 !=res_2)
    {
        cout << "false";
        return 0;
    }
    if (res_3 != res_4)
    {
        cout << "false";
        return 0;
    }
    cout << "true";
    return 1;
     
}
/**************************************************************
    Problem: 1182
    User: 181860077
    Language: C++
    Result: 正确
    Time:56 ms
    Memory:1808 kb
****************************************************************/
