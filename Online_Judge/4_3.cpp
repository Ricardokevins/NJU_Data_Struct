/*
问题 C: 小蓝鲸的散步
时间限制: 1 Sec  内存限制: 64 MB
提交: 37  解决: 12
[提交][状态][讨论版]
题目描述
小蓝鲸想放松一下，于是打算去著名的二叉树公园散步。 

二叉树公园有n个景点，某些景点之间由一条小路连接。没错，和你想的一样，这个公园之所以叫“二叉树”公园，就是因为这些小路将景点连成了一个二叉树。所有景点的编号是0到n-1。0号景点是二叉树公园的根节点。所有小路的长度为1。 

小蓝鲸打算从某一个景点进入公园散步，散步完成后再从某一个景点离开公园。她觉得二叉树非常优美，因此对二叉树公园很好奇，想每个景点都能散步到。但是，她也不想太累，所以散步的总路程要最短。 

她希望聪明的你能告诉她最短的路程是多少。 

注意观察样例，或许能得从中到启发。

输入
第1行一个正整数n，表示二叉树公园景点的个数。 

第2到第n+1行，每行有两个整数l和r，用空格隔开。第i+2行的l表示景点l是景点i的左儿子，r表示景点r是景点i的右儿子。当l或者r为-1时，表示这个儿子不存在。

（1≤ n  ≤ 105）

输出
一行，一个正整数，表示小蓝鲸最短所需要走的路程。
样例输入
9
1 2
3 4
-1 -1
5 -1
-1 6
7 -1
-1 8
-1 -1
-1 -1
样例输出
10
*/
#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
 
int print(Node* a)
{
    if (a == NULL)
        return 0;
    print(a->left);
    cout << a->val << endl;
    print(a->right);
    return 0;
}
 
int dfs(Node* a, int& dis)
{
    if (a == NULL)
    {
        return 0;
    }
    int left = (dfs(a->left, dis));
    int right = (dfs(a->right, dis));
    dis = left + right > dis ? left + right : dis;
    return left > right ? left + 1 : right + 1;
 
}
 
int count(Node* a)
{
    int diameter(0);
    dfs(a, diameter);
    return diameter;
}
 
int main()
{
    int Node_num(0);
    int num(0);
    cin >> num;
    vector<Node*> opr;
    Node root;
    root.left = NULL;
    root.right = NULL;
    root.parent = NULL;
    Node_num++;
    root.val = 0;
    opr.push_back(&root);
    for (int i(1); i <num; i++)
    {
        int left;
        int right;
        cin >> left;
        cin >> right;
        if (left != -1)
        {
            Node* temp = new Node;
            temp->left = NULL;
            temp->right = NULL;
            temp->val = left;
            temp->parent = opr[0];
            opr[0]->left = temp;
            opr.push_back(temp);
            Node_num++;
        }
        if (right != -1)
        {
            Node* temp = new Node;
            temp->left = NULL;
            temp->right = NULL;
            temp->val = right;
            temp->parent = opr[0];
            opr[0]->right = temp;
            opr.push_back(temp);
            Node_num++;
        }
        opr.erase(opr.begin());
    }
    int dia = count(&root);
    int other = Node_num - (dia + 1);
    int finalres = dia + 2 * other;
    cout <<finalres << endl;
    return 0;
}
 
/**************************************************************
    Problem: 1179
    User: 181860077
    Language: C++
    Result: 正确
    Time:1072 ms
    Memory:3920 kb
****************************************************************/
