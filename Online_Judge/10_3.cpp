/*
问题 C: 小蓝鲸捡金币
时间限制: 1 Sec  内存限制: 10 MB
提交: 223  解决: 53
[提交][状态][讨论版]
题目描述
给定一个有向图，每个节点都包含一种类别的金币，用26个小写英文字母表示26种不同的金币类别，假设每个节点都有任意多的金币可以捡取。
小蓝鲸可以从图的任意定点出发，沿着有向边前进，直到无法继续前进为止。记小蓝鲸走过的路径为s，对于每个走过的节点，小蓝鲸可以捡取这个节点中的一枚金币。但是在整个路径s中，小蓝鲸只能捡取同一种类别的金币。现在小蓝鲸想知道自己最多可以捡到多少金币。
输入
第一行两个int型数，代表有向图的节点数目N和边数M，节点编号为[1-N]。
第二行一个长度为N的字符串，第i (1 ≤i≤ N)个字母代表编号为i的节点对应的金币类别。
之后有M行输入，每行有2个数x,y，代表一条从编号为x的节点到编号为y的节点的有向边。

(0 ≤ N ≤ 1000，0 ≤ M ≤ 5000)

输出
一个int型数，小蓝鲸最多能捡到金币。如果小蓝鲸可以捡到任意多的金币（图中有环），那么返回-1
样例输入
6 6
aacabc
1 2
1 3
3 5
3 6
4 2
4 1
样例输出
3
提示
Note: 路径为 4->1->2

[提交][状态]
*/

#include<iostream>
#include<vector>
#include<string>
#include<memory.h>
#define maxm 6000
#define maxn 2000
using namespace std;
 
 
 
int countNow;
int InDegree[maxn];
int root[maxm];
 
int n, m;
int coin[maxm];
 
vector<int> TuoPu;
 
int length[26][maxm];
 
struct edge {
    int terminal, next, len;
};
edge Edge[maxm];
 
void init() {
     
    countNow = 0;
    for (int i = 0; i < maxn; i++) InDegree[i] = 0;
    memset(length, 0, sizeof(length));
    memset(root, -1, sizeof(root));
 
}
 
 
bool find_loop() {
    vector<int>q;
 
    for (int i = 1; i <= n; i++) {
        if (InDegree[i] == 0) {
            q.push_back(i);
 
        }
 
    }
    for (int i(0); i < q.size(); i++) {
        TuoPu.push_back(q[i]);
        for (int j = root[q[i]]; j >= 0; j = Edge[j].next) {
            int v = Edge[j].terminal;
            if (--InDegree[v] == 0) q.push_back(v);
 
        }
    }
 
    if (q.size() == n + 1) return 0;
    else return 1;
}
 
 
 
 
 
 
 
 
 
int main() {
 
    init();
    cin >> n >> m;
    string x;
    cin >> x;
    for (int i = 1; i <= n; i++) {
        coin[i] = x[i - 1] - 'a' + 1;
    }
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        InDegree[v]++;
        Edge[countNow].terminal = v;
        Edge[countNow].next = root[u];
        Edge[countNow].len = 0;
        root[u] = countNow++;
 
 
    }
    for (int i = 1; i <= n; i++) {
        InDegree[n+1]++;
        Edge[countNow].terminal = n+1;
        Edge[countNow].next = root[i];
        Edge[countNow].len = 0;
        root[i] = countNow++;
    }
 
 
    if (find_loop()) {
        cout << "-1";
    } else {
        int MaxNumber = -1;
 
        for (int k(0); k < 26; k++) {
            for (int i (0); i < TuoPu.size(); i++) {
                int sorti = TuoPu[i];
                for (int j = root[sorti]; j >= 0; j = Edge[j].next) {
                    int tmphead = Edge[j].terminal;
 
                    int tmp = length[k][sorti] + (int)(coin[sorti] == (k + 1));
                    if (tmp > length[k][tmphead]) length[k][tmphead] = tmp;
 
                }
 
            }
 
            for (int i (1); i <= n + 1; i++) {
                if (length[k][i] > MaxNumber) MaxNumber = length[k][i];
 
            }
        }
        cout<<MaxNumber;
    }
 
 
    return 0;
 
 
}
/**************************************************************
    Problem: 1205
    User: 181860077
    Language: C++
    Result: 正确
    Time:52 ms
    Memory:2276 kb
****************************************************************/