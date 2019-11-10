/*
问题 D: 五行(选做)
时间限制: 1 Sec  内存限制: 128 MB
提交: 185  解决: 22
[提交][状态][讨论版]
题目描述
五行中的金、木、水、火、土相生相克。他们的相克关系构成了一个环：金克木，木克土，土克水，水克火，火克金。

现在有N个物体，每个物体分别属于五行中的某一类，编号为0到N-1。

小蓝鲸想和你玩一个游戏：她说M句话，每句话的形式是`kind x y`，你需要再最后告诉她，有几句话是假话。

其中，`x`和`y`表示物体的编号。`kind`是`0`或者`1`，`0`表示`x`和`y`属于五行中的同一类，`1`表示`x`的五行属性克制`y`的五行属性。

如果某句话和前面的话相矛盾，那么这句话就是假话。在之后的判断中，你应该忽略之前已判断为假话的话。

输入
第一行2个正整数N和M。满足1≤N≤5×104，1≤M≤105。

接下来有M行，每行都是3个用空格隔开的非负整数，具体含义如上文所描述。

输出
一行，一个正整数，表示答案。


样例输入
5 5
1 2 2
1 1 0
0 4 1
1 3 0
0 3 3
样例输出
1
提示
*/

#include<iostream>
#include<vector>
using namespace std;
#define max_size 1000000
int relation[max_size] = { 0 };
int previous[max_size] = { 0 };
int member[max_size] = { 0 };
int to_find(int x)
{
    if (previous[x] == x)
        return x;
    int mem = 0;
    while (previous[x] != x)
    {
        member[mem++] = x;
        x = previous[x];
    }
    member[mem] = x;
    while (mem--)
    {
        relation[member[mem]] = (relation[member[mem]] + relation[member[mem + 1]]) % 5;
        previous[member[mem]] = x;
    }
    return previous[*member];
 
}
 
int to_merge(int t, int x, int y)
{
    int x_grand = to_find(x);
    int y_grand = to_find(y);
    if (x_grand == y_grand)
    {
        return ((t + relation[y]) % 5 == relation[x]);
    }
    previous[x_grand] = y_grand;
    relation[x_grand] = (relation[y] - relation[x] + t + 5) % 5;
    return true;
}
 
int main()
{
    int num1;
    int num2;
    cin >> num1;
    cin >> num2;
    int result(0);
    for (int i(0); i <= num1; i++)
    {
        previous[i] = i;
    }
    while (num2 > 0)
    {
        int data1;
        int data2;
        int data3;
        cin >> data1;
        cin >> data2;
        cin >> data3;
        if (data2 > num1 || data3 > num1 || !to_merge(data1, data2+1, data3+1))
            result++;
        num2--;
    }
    cout << result;
    return 0;
 
}