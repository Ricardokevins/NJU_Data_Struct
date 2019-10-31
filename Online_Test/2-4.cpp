/*
问题 D: 礼物圣诞树
时间限制: 1 Sec  内存限制: 10 MB
提交: 35  解决: 12
[提交][状态][讨论版]
题目描述
为了迎接圣诞节，小蓝鲸买了许多装饰挂件来装点圣诞树，希望可以将挂件均匀的挂在圣诞树上，但是这些挂件目前集中在圣诞树的部分位置，且只能在树枝之间移动调整挂件位置，小蓝鲸希望你帮忙帮助他对圣诞树进行调整。 

圣诞树使用一棵二叉树进行表示，二叉树的节点存储该节点所放置的挂件数目，已知总的挂件数目与二叉树节点数相同，将一个挂件从一个节点移动至相邻节点为移动一步，请告诉小蓝鲸完成挂件调整，使得每个节点有且仅有一个挂件，需要移动挂件的最小步数是多少？
输入
一行，二叉树对应的前序遍历表示，用空格分割。其中-1表示空的叶子结点，其他自然数表示这个节点上的挂件数目。 （1≤非空节点的个数≤10000）
输出
一行，一个整数，表示最小的移动步数。
样例输入
2 0 0 3 -1 -1 0 -1 -1 -1 0 2 -1 1 -1 -1 2 -1 0 -1 -1
样例输出
6
提示

样例输入对应的二叉树和挂件移动方式如下： 
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
vector<int>tree1;
int change_num(string a)
{
    int num(0);
    int flag(0);
    if (a.size() == 0)
        return num;
    if (a[0] == '-')
    {
        flag = 1;
        a.erase(a.begin());
    }
    while (a.size() != 0)
    {
        num = num * 10;
        num += a[0] - '0';
        a.erase(a.begin());
    }
    if (flag)
        num = -num;
    return num;
}
Node* build1(int& pos,Node *root)
{
    if (pos > tree1.size())
    {
        return NULL;
    }
    if (tree1[pos] == -1)
    {
        pos += 1;
        return NULL;
    }
    Node* temp = new Node;
    temp->val = tree1[pos];
    temp->parent = root;
    pos += 1;
    temp->left = build1(pos,temp);
    temp->right = build1(pos,temp);
    return temp;
}
vector<vector<Node*>>LTree;
void visit1(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val<<endl;
    visit1(root->left);
    visit1(root->right);
    return;
}
void levelOrder(Node* root) {
    vector<Node*>opr1;
    vector<Node*>opr2;
     
    if (root == NULL)
        return ;
    opr1.push_back(root);
    int flag = 2;
    while (1)
    {
        if (flag == 1)
        {
            if (opr2.size() == 0)
            {
                break;
            }
            for (int i(0); i < opr2.size(); i++)
            {
                if (opr2[i]->left != NULL)
                {
                    opr1.push_back(opr2[i]->left);
                }
                if (opr2[i]->right != NULL)
                {
                    opr1.push_back(opr2[i]->right);
                }
            }
            LTree.push_back(opr2);
            opr2.clear();
            flag = 2;
        }
        if (flag == 2)
        {       
            if (opr1.size() == 0)
            {
                break;
            }
            for (int i(0); i < opr1.size(); i++)
            {
                if (opr1[i]->left != NULL)
                {
 
                    opr2.push_back(opr1[i]->left);
                }
                if (opr1[i]->right != NULL)
                {
                    opr2.push_back(opr1[i]->right);
                }
            }
            LTree.push_back(opr1);
            opr1.clear();
            flag = 1;
        }
    }
}
 
int  main()
{
    string a;
    getline(cin, a);
    string temp;
    if (a.size() == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i(0); i < a.size(); i++)
    {
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
                num = change_num(temp);
                tree1.push_back(num);
                temp.clear();
            }
        }
    }
    int num(0);
    num = change_num(temp);
    tree1.push_back(num);
    temp.clear();
    int pos1(0);
    Node* Tree1 = build1(pos1,NULL);
    int result(0);
    levelOrder(Tree1);
    int i = int(LTree.size() - 1);
    for (; i >= 0; i--)
    {
        for (int j(0); j < LTree[i].size(); j++)
        {
            while (LTree[i][j]->val > 1)
            {
                if (LTree[i][j]->left != NULL)
                {
                    if (LTree[i][j]->left->val < 1)
                    {
                        LTree[i][j]->left->val = 1;
                        LTree[i][j]->val -= 1;
                        result += 1;
                        continue;
                    }
                }
                if (LTree[i][j]->right != NULL)
                {
                    if (LTree[i][j]->right->val < 1)
                    {
                        LTree[i][j]->right->val = 1;
                        LTree[i][j]->val -= 1;
                        result += 1;
                        continue;
                    }
                }
                if (LTree[i][j]->parent == NULL)
                    break;
                LTree[i][j]->parent->val += LTree[i][j]->val - 1;
                result += LTree[i][j]->val - 1;
                LTree[i][j]->val = 1;
            }
        }
    }
    cout << result;
     
    return 0;
}
/**************************************************************
    Problem: 1185
    User: 181860077
    Language: C++
    Result: 答案错误
****************************************************************/

