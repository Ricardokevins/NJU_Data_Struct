/*
问题 A: 排队
时间限制: 2 Sec  内存限制: 64 MB
提交: 311  解决: 85
[提交][状态][讨论版]
题目描述
小蓝鲸的班级要出去春游，作为班⻓的她要负责给同学们排队。班⾥共有N个同学，每个同学的学号是0到N-1的某个数字，且两两之间学号不同。队伍从左往右排。有M个同学告诉小蓝鲸，在排队时他 们想在某个同学的左边（不⼀定要相邻）。小蓝鲸在满⾜了他们的要求之后，发现可能有多种排队⽅ 式，小蓝鲸决定选择排完之后字典序最小的排队⽅式。

数列 l1的字典序小于数列 ，当且仅当满⾜下⾯的某个条件：

1. l1是 l2 的前缀（l1的⻓度⽐ l2短）。 

2. l1和 l2的公共前缀记为p 。 l1和 l2 都去掉前缀p后，l1的第⼀个数字⽐ l2的第⼀个数字小。
例如：
1. 1 2 3 的字典序小于 1 2 3 4 。 

2. 1 2 3 的字典序小于 1 2 4 。

输入
第1⾏有2个空格分隔的正整数N和M。
接下来有M⾏，每⾏有2个空格分隔的⾮负整数ai和bi，表⽰学号为ai的同学要排到学号为bi同学的左边。

( 1 ≤ N, M ≤ 6×105 ) , ( 0 ≤ ai, bi ＜ N, ai ≠ bi )

输出
⼀⾏N个以空格隔开的⾮负整数，表⽰队伍中从左往右的同学的学号。行末无空格。
样例输入
5 6
1 2
3 1
1 0
4 1
4 0
3 0
样例输出
3 4 1 0 2
提示
*/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
 
struct Node {
    Node* next;
    int num;
};
vector<Node*>vex;
vector<int>count_degree;
int vex_num;
int edge_num;
 
void create_graph()
{
    cin >> vex_num;
    cin >> edge_num;
    for (int i(0); i < vex_num; i++)
    {
        Node* temp = new Node;
        temp->next = NULL;
        temp->num = i;
        vex.push_back(temp);
        count_degree.push_back(0);
    }
    for (int i(0); i < edge_num; i++)
    {
        int a, b;
        cin >> a >> b;
        Node* target = vex[a];
        while (target->next != NULL)
        {
            target = target->next;
        }
        Node* temp2 = new Node;
        temp2->num = b ;
        temp2->next = NULL;
        target->next = temp2;
    }
}
 
void print_graph() {
    int count = 0;
    cout << "graph as below " << endl;
 
    for (int i(0); i < vex_num; i++)
    {
        cout << vex[i]->num << " ";
        Node* cur = vex[i]->next;
        while (cur != NULL)
        {
            cout << "<" << vex[i]->num << "," << cur->num << ">   ";
            cur = cur->next;
        }
        cout << endl;
    }
 
}
vector<int>result;
int get_by_TuoPu()
{
    //cout << "Tuo Pu sort result as followed: " << endl;
    priority_queue<int, vector<int>, greater<int> > node;
 
    for (int i(0); i < vex_num; i++)
    {
        Node* temp = vex[i]->next;
        while (temp != NULL)
        {
            count_degree[temp->num]++;
            temp = temp->next;
        }
    }
    for (int i(0); i < vex_num; i++)
    {
        if (count_degree[i] == 0)
        {
            node.push(i);
        }
    }
    int count(0);
    while (!node.empty())
    {
        int cur = node.top();
        node.pop();
        result.push_back(vex[cur]->num);
        //cout << vex[cur]->num << " ";
        Node* temp2 = vex[cur]->next;
        while (temp2 != NULL)
        {
            count_degree[temp2->num]--;
            if (count_degree[temp2->num] == 0)
            {
                node.push(temp2->num);
            }
            temp2 = temp2->next;
        }
        count++;
    }
    if (count == vex_num)
    {
        //cout << endl;
        return 1;
    }
    else
    {
        //cout << "this graph has loop . System Error Hit bad trap" << endl;
        return 0;
    }
}
 
 
 
/*
testcase:
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5
*/
 
int main()
{
    create_graph();
    //print_graph();
    get_by_TuoPu();
    //cout << endl << endl;
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
    Problem: 1203
    User: 181860077
    Language: C++
    Result: 正确
    Time:15624 ms
    Memory:35668 kb
****************************************************************/