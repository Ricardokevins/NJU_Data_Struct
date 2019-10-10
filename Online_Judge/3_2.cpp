/*
题目描述
给定一个英文句子，要求翻转句中单词的顺序，单词本身不变，其中，句子没有标点，单词之间以空格隔开。

 

要求：用链表实现，每个链表结点的数据域为一个字符（char型）。本题不允许使用C++标准库提供额外帮助。 

输入
一个英文句子，仅由 'a'~'z'和‘A’~‘Z’和空格‘ ’构成，字符串长度len满足，0≤len≤100000

输出
翻转后的英文句子，行末无多余空格换行符。

样例输入
I am a student
样例输出
student a am I
*/
#include<iostream>
using namespace std;
struct Node {
    char data;
    Node* left;
    Node* right;
};
int main() {
    char temp[1000000] = { 0 };
    Node* head = NULL;
    Node* now = NULL;
    cin.getline(temp, 1000000);
 
    for (int i(0); temp[i] != '\0'; i++) {
        Node* cur = new Node;
        if (head == NULL) {
            head = cur;
            now = cur;
            cur->left = NULL;
            cur->right = NULL;
            cur->data = temp[i];
        }
        else {
            now->right = cur;
            cur->left = now;
            cur->right = NULL;
            cur->data = temp[i];
            now = cur;
        }
    }
    char word[100000] = { 0 };
    int i(0);
    if (now == NULL)
    {
        cout << "" << endl;
        return 0;
    }
    while (now != NULL) {
        if (now->data != ' ') {
            word[i] = now->data;
            i++;
            now = now->left;
        }
        else {
            for (int j(i-1); j >= 0; j--) {
                cout << word[j];
                word[j] = '\0';
            }
            cout << " ";
            i = 0;
            now = now->left;
        }
    }
    for (int j(i-1); j >= 0; j--) {
        cout << word[j];
    }
    cout << endl;
    //cout << "final" << endl;
    return 0;
}
 
 
/**************************************************************
    Problem: 1176
    User: 181860077
    Language: C++
    Result: 正确
    Time:92 ms
    Memory:3936 kb
****************************************************************/
