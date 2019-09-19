/*
班主任需要从班级⾥选举⼀位同学作为班⻓，并通过以下⽅式进⾏选择。将所有N位同学按照从1⾄N进⾏编号，并按照顺时针围成⼀个圈(N号在1号左侧)，
⼀位教师从1开始顺时针⽅向，清点⾄第K个同学；另⼀位教师从N开始逆时针⽅向，清点⾄第M个同学。若这两个同学是同⼀个学⽣，则此⼈为选定的班⻓
；若不是同⼀个学⽣，则将其从队列中去除，并从下⼀个同学开始继续清点，直到选出班⻓或者 队列中没有同学位置。请你利⽤循环双向链表编写程序
解决这⼀问题。
输入
⼀⾏，三个数字 N,K,M，以空格隔开。（0<K , M<N<100）
输出
⼀⾏，每⼀次清点选出的同学原始编号，以空格分开，⾏末⽆空格。
注意，若两个学⽣不同，每组先输出顺时针选择结果，后输出逆时针结果。
*/


#include<iostream>
using namespace std;

struct Node
{
	int val;
	int flag;
	Node* left;
	Node* right;
};
Node * moveleft(Node* head, int a)
{
	while (head != NULL && a-1 > 0)
	{
		while (head->left->flag == 0)
		{
			head = head->left;
		}
		head = head->left;
		a--;
	}
	return head;
}
Node* moveright(Node* head, int a)
{
	while (head != NULL && a-1 > 0)
	{
		while (head->right->flag== 0)
		{
			head = head->right;
		}
		head = head->right;
		a--;
	}
	return head;
}
int testall(Node* head)
{
	Node* temp = head;
	do {
		if (temp->flag == 1)
			return 1;
		temp = temp->right;
	} while (temp != head);
	return 0;
}

int main()
{
	int n(0);
	int k(0);
	int m(0);
	while (cin >> n)
	{
		if (n <= 0)
			return 0;
		cin >> k;
		cin >> m;
		Node* head = new Node;
		head->left = NULL;
		head->right = NULL;
		head->val = 1;
		head->flag = 1;
		Node* cur = head;
		Node* fin = head;
		for (int i = 2; i < n + 1; i++)
		{
			Node* hhh = new Node;
			hhh->val = i;
			cur->right = hhh;
			hhh->left = cur;
			hhh->right = NULL;
			hhh->flag = 1;
			cur = hhh;
		}
		
	
		
		cur->right = head;
		head->left = cur;
		
		Node* rtarget = head;
		Node* ltarget = cur;
		while (head->val != cur->val)
		{
			rtarget = moveright(head, k);
			ltarget = moveleft(cur, m);
			if (rtarget->val == ltarget->val)
			{
				cout  << rtarget->val << endl;
				return 0;
			}
			cout << rtarget->val << " " << ltarget->val << " " ;
			rtarget->flag = 0;
			ltarget->flag = 0;
			//cout << rtarget->val << "              " << ltarget->val << endl;
			if (testall(head))
			{
				head = moveright(rtarget, 2);
				cur = moveleft(ltarget, 2);
			}
			else
				return 0;
			//cout << head->val << "              " << cur->val << endl;
			//Node* temp = fin;
			//do {
			//	cout <<temp->val<<"  "<< temp->flag << endl;
			//	temp = temp->right;
			//} while (temp != fin);
		}
		cout  << head->val << endl;
		return 0;
	}
}
