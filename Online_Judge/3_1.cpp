/*
题目描述
现有一个由 '(' 和 ')' 括号组成的字符串 S，聪明的小蓝鲸可以在任何位置添加最括号 '(' 或 ')'，使得到的括号字符串有效。这里要求添加的括号数最少。

 

从形式上讲，只有满足下面几点之一，括号字符串才是有效的：

1.它是一个空字符串，或者 

2.它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者 

3.它可以被写作 (A)，其中 A 是有效字符串。 

 

给定一个括号字符串，返回为使结果字符串有效而必须添加的最少括号数。

 

注意：空字符串可被认为是有效字符串，本题不允许使用C++标准库提供额外帮助。

输入
一行字符串，仅由 '('，')' 构成，字符串长度len满足，0≤len≤1000000

输出
使结果字符串有效而必须添加的最少括号数，行末无多余空格换行符。

样例输入
())
样例输出
1
*/
#include<iostream>
using namespace std;
struct Node {
    char data;
    Node* left;
    Node* right;
};
int main() {
    char temp[1000001] = { 0 };
    Node* head = NULL;
    Node* now = NULL;
    cin.getline(temp, 1000001);
    int right(0);
    int left(0);
    for (int i(0); temp[i] != '\0'; i++) 
    {
        if(temp[i]=='(') 
        {
            left++;
        } 
        else
        {
            left--;
        }
        if (left == -1)
        {
            right += 1;
            left += 1;
        }
    }
    cout<< left+right;
    return 0;
}
/**************************************************************
    Problem: 1175
    User: 181860077
    Language: C++
    Result: 正确
    Time:188 ms
    Memory:2392 kb
****************************************************************/
