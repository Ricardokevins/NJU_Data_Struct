/*
问题 A: 寻找高频元素
时间限制: 1 Sec  内存限制: 10 MB
提交: 356  解决: 112
[提交][状态][讨论版]
题目描述
现有一个非空的正整数数组，长度为N，数组中不相同的元素出现的频率不同，返回其中出现频率前k高的元素。

注意：本题不允许使用C++标准库提供额外帮助。

输入
第一行：数组长度N，1≤N≤1000

第二行：非空的正整数数组，每个元素用空格隔开

第三行：k，1≤k≤数组中不相同元素的个数
输出
出现频率前k高的元素，按照出现频率由高到低排列，元素之间用空格隔开，行末无多余空格换行符。

样例输入
6
2 1 2 2 1 3
2
样例输出
2 1
*/
#include<iostream>
using namespace std;
struct Node {
    int a;
    int fre;
    Node* next;
};
int findmax(Node* root)
{
    int max(-1);
    int val(0);
    Node* hhh = root;
    while (root != NULL)
    {
        if (root->fre > max)
        {
            max = root->fre;
            val = root->a;
            hhh = root;
        }
        root = root->next;
    }
    hhh->fre = -1;
    return val;
}
int main()
{
    int num(0);
    cin >> num;
    Node* head = NULL;
    for (int i(0); i < num; i++)
    {
        int temp(0);
        cin >> temp;
        if (head == NULL)
        {
            Node* tempa = new Node;
            tempa->a = temp;
            tempa->fre = 1;
            tempa->next = NULL;
            head = tempa;
        }
        else
        {
            Node* cur = head;
            Node* pre = cur;
            while (cur != NULL)
            {
                if (cur->a == temp)
                {
                    cur->fre++;
                    break;
                }
                pre = cur;
                cur = cur->next;
            }
            if (cur == NULL)
            {
                Node* tempa = new Node;
                tempa->a = temp;
                tempa->fre = 1;
                tempa->next = NULL;
                pre->next = tempa;
            }
        }
    }
    int num2(0);
    cin >> num2;
    for (int i(0); i < num2; i++)
    {
        cout << findmax(head);
        if (i != num2 - 1)
        {
            cout << " ";
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1183
    User: 181860077
    Language: C++
    Result: 正确
    Time:36 ms
    Memory:1536 kb
****************************************************************/
