/*
问题 C: 奇怪的⼆叉搜索树
时间限制: 3 Sec  内存限制: 64 MB
提交: 325  解决: 120
[提交][状态][讨论版]
题目描述
小蓝鲸学习了⼆叉搜索树后，去OJ上找到了⼀个相关的题⽬练⼿。题⽬如下：

输⼊ N个数字，你需要把这 N个数字依次按照⼆叉搜索树的插⼊⽅法插⼊到⼀个初始为空树的⼆叉搜索树中。你需要依次输出输⼊中的后 N-1个数字在⼆叉搜索树中的⽗节点中保存的数字。
 小蓝鲸觉得这个题⽬很简单，按照题意写了⼀发课上教的⼆叉搜索树，OJ却提⽰ Time Limit Exceeded 。机智的她⻢上想到：如果输⼊的数据是单调的，那么⼆叉搜索树就会退化成⼀条链，这样光插⼊所有输⼊数据就是 O(N2)的复杂度了，肯定会超时呀。
这让她很奇怪。于是，她向乐于助⼈的你寻求帮助。
注意：本题可以使⽤STL，例如： vector 、 queue 、 set 和 map 等。

输入
第⼀⾏⼀个正整数N 。（2≤N≤5×104）
第⼆⾏ N个以空格分隔的两两不同的正整数 ai。（1≤ai≤2×109） 
输出
一行N-1个以空格分隔的数字，代表输⼊中的后N-1个数字在⼆叉搜索树中的⽗节点中保存的数字。



样例输入
5
1252372126 320842920 1690857990 1211251133 1393487776
样例输出
1252372126 1252372126 320842920 1690857990
提示
[提交][状态]
*/
#include <iostream>
#include <vector>
using namespace std;
 
struct Node
{
    int val;
    Node *parent = NULL;
     
    Node *left = NULL;
     
    Node *right = NULL;
};
 
int main()
{
    int num;  
    scanf("%d", &num);
     
     
    vector<int> result;
    int data;
    scanf("%d", &data);
     
    Node *root = new Node;
    root->val = data;
    for (int i(0); i < num - 1; i++)
    {
        int temp;
        scanf("%d", &temp);
        Node *node = new Node;
        node->val = temp;
        Node *p = root;
        while (p)
        {
            if (temp < p->val)
            {
                if (p->left)
                    p = p->left;
                else
                {
                    p->left = node;
                    node->parent = p;
                    result.push_back(p->val);
                    break;
                }
            }
            else if (temp > p->val)
            {
                if (p->right)
                    p = p->right;
                else
                {
                    p->right = node;
                    node->parent = p;
                    result.push_back(p->val);
                    break;
                }
            }
        }
    }
    for (int i(0); i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1197
    User: 181860077
    Language: C++
    Result: 正确
    Time:3820 ms
    Memory:2880 kb
****************************************************************/