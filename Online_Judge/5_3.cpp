/*
问题 C: 装饰圣诞树
时间限制: 1 Sec  内存限制: 128 MB
提交: 43  解决: 26
[提交][状态][讨论版]
题目描述
圣诞节前夕，小蓝鲸和室友们决定给寝室的二叉圣诞树挂上灯烛和装饰品，由于繁重的课业压力导致小蓝鲸没有足够的时间精力对圣诞树进行修剪，树的枝杈略显杂乱。以一种n=13个节点的圣诞树结构为例，节点从1开始按层编号。

 

小蓝鲸和室友们决定，只把树的边缘的节点挂上装饰品，小蓝鲸所认为的边缘是指：从圣诞树的左侧或右侧向另一侧望去，所能看到的所有未被挡住的节点。对于图1的圣诞树，需要装饰的边缘节点即为1、2、3、4、6、7、10、11、13。小蓝鲸希望你能帮助他找出这些需要挂上装饰品的节点编号。

输入
第1行一个正整数n，表示圣诞树的节点总数。满足1≤n≤30。

第2到n+1行，每行有两个整数。第i+1(1≤i≤n)行的整数表示第i个节点的左右子节点编号，-1代表该节点没有左节点或右节点。

输出
输出仅一行整数，按照节点编号从小到大的顺序，输出需要装饰的节点编号。行末无多余空格换行符。
样例输入
13
2 3
-1 4
5 6
7 8
9 -1
10 -1
-1 -1
11 -1
-1 -1
12 13
-1 -1
-1 -1
-1 -1
样例输出
1 2 3 4 6 7 10 11 13
提示
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
    root.val = 1;
    opr.push_back(&root);
    for (int i(1); i < num; i++)
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
    vector<Node*>opr1;
    vector<Node*>opr2;
    opr1.push_back(&root);
    int flag = 2;
    vector<int>result;
    while (1)
    {
        if (flag == 1)
        {
            vector<int>temp2;
            if (opr2.size() == 0)
            {
                break;
            }
            for (int i(0); i < opr2.size(); i++)
            {
                temp2.push_back(opr2[i]->val);
                if (opr2[i]->left != NULL)
                {
                    opr1.push_back(opr2[i]->left);
                }
                if (opr2[i]->right != NULL)
                {
                    opr1.push_back(opr2[i]->right);
                }
            }
            if (temp2.size() == 1)
            {
                result.push_back(temp2[0]) ;
            }
            else
            {
                result.push_back(temp2[0]); 
                result.push_back(temp2[temp2.size() - 1]);
            }
            opr2.clear();
            flag = 2;
        }
        if (flag == 2)
        {
            vector<int>temp2;
            if (opr1.size() == 0)
            {
                break;
            }
            for (int i(0); i < opr1.size(); i++)
            {
                temp2.push_back(opr1[i]->val);
                if (opr1[i]->left != NULL)
                {
 
                    opr2.push_back(opr1[i]->left);
                }
                if (opr1[i]->right != NULL)
                {
                    opr2.push_back(opr1[i]->right);
                }
            }
            if (temp2.size() == 1)
            {
                result.push_back(temp2[0]);
            }
            else
            {
                result.push_back(temp2[0]);
                result.push_back(temp2[temp2.size() - 1]);
            }
            opr1.clear();
            flag = 1;
        }
    }
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
    Problem: 1181
    User: 181860077
    Language: C++
    Result: 正确
    Time:24 ms
    Memory:1548 kb
****************************************************************/
