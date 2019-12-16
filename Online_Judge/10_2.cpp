/*
问题 B: 小蓝鲸的旅游
时间限制: 1 Sec  内存限制: 64 MB
提交: 392  解决: 54
[提交][状态][讨论版]
题目描述
小蓝鲸和朋友规划⼀起开⻋去n个地点，但是不清楚到这些地⽅的最短距离，希望你能帮忙计算出来到 各个地⽅的最短距离。 

由于小蓝鲸和她的朋友对这n个地点并不完全熟悉，所以，他们计划某些路段由小蓝鲸调研路线开⻋前 往，另⼀些路段由她的朋友调研路线开⻋前往。为了避免旅途中过于劳累，他们决定每到达⼀个地⽅就 交换驾驶员，以便双⽅交替休息。 

小蓝鲸想请你帮忙设计算法，计算出到达每个地点的最短路径，以便她们安排⾏程。小蓝鲸从0号地点出发。

输入
第⼀⾏输⼊数字n和m，分别表⽰n个地点与m条路径⻓度，地点编号为0到n-1。
后m⾏输⼊为每条路径的信息，为⼀个四元组s,e,l,c，分别表⽰边的起始地点s，路径的终点e，路径的⻓度l, 以及该段路径的驾驶⼈员c。

( 0 ≤ n ≤ 1000，1 ≤ m ≤ n2 ， 1 ≤ l ≤ 100，c∈{1,2} )

输出
n个数字，以空格隔开，表⽰0号地点到其他所有地点的最短距离，-1表⽰⽆法到达。行末有空格
样例输入
6 6
0 1 1 1
0 3 2 2
1 2 2 2
3 2 1 1
2 4 3 1
4 5 1 2
样例输出
0 1 3 2 6 7 
提示
*/
#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;
 
#define MAXN 1000005
#define INT_MAX 2147483647
 
 
 
 
struct SimpleEdge { 
    int driver;
    int val;
    int v;
    SimpleEdge(int _val, int _v, int _c) {
        val = _val;
        v = _v;
        driver = _c;
    }
 
};
 
struct edge {
    int stop;
    int len;
    int next;
    int driver;
} Edge[MAXN];
 
struct Compare {
    bool operator()(SimpleEdge a, SimpleEdge b) {
        return a.val > b.val;
    }
};
int head[MAXN];
int Distance[2][1005];
 
priority_queue<SimpleEdge, vector<SimpleEdge>, Compare> dist;
 
int vex_num;
int edge_num;
 
 
int min(int x, int y) {
    if(x<y)
        return x;
    else
        return y;
}
 
 
int main() {
 
    cin >> vex_num >> edge_num;
 
    for (int i = 0; i < MAXN; i++) {
        Edge[i].next = -1;
        head[i] = -1;
    }
    int CountNow = 0;
 
    for (int i = 0; i < edge_num; i++) {
        int a, b, c, d;
        cin >>a >> b >> c >> d;
        Edge[CountNow].stop = b;
        Edge[CountNow].len = c;
        Edge[CountNow].next = head[a];
        Edge[CountNow].driver = d - 1;
        head[a] = CountNow++;
    }
 
 
    for (int i = 0; i < vex_num; i++) {
        Distance[0][i] = INT_MAX;
        Distance[1][i] = INT_MAX;
 
    }
    Distance[0][0] = 0;
    Distance[1][0] = 0;
 
    SimpleEdge tmp(0,0,0);
 
    dist.push(tmp);
 
    tmp.driver = 1;
 
    dist.push(tmp);
 
 
    while (!dist.empty()) {
        SimpleEdge Head = dist.top();
        dist.pop();
        int c = Head.driver;
        int len = Head.val;
        int v = Head.v;
        if (Distance[c][v] < len) continue;
        for (int i = head[v]; i >= 0; i = Edge[i].next) {
            edge Nowedge = Edge[i];
            if ((Nowedge.driver!=c)&&Distance[Nowedge.driver][Nowedge.stop] > Distance[c][v] + Nowedge.len) {
                Distance[Nowedge.driver][Nowedge.stop] = Distance[c][v] + Nowedge.len;
                 
                SimpleEdge NewEdge(Distance[Nowedge.driver][Nowedge.stop], Nowedge.stop, Nowedge.driver);
                dist.push(NewEdge);
            }
        }
    }
 
 
    for (int i = 0; i < vex_num; i++) {
        int edge_num = min(Distance[0][i], Distance[1][i]);
        if (edge_num != INT_MAX)
            cout << edge_num;
        else
            cout << "-1";
        if (i != vex_num-1)
            cout << " ";
    }
    return 0;
 
}
/**************************************************************
    Problem: 1204
    User: 181860077
    Language: C++
    Result: 正确
    Time:448 ms
    Memory:21272 kb
****************************************************************/