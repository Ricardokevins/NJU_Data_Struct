/*
现在有⼀组链表存储的数据，我们想对链表中的数据按照⼤小划分成两个部分。给定⼀个划分值x，所有⼤于或者等于x的节点都放到所有小于x的节点的后⾯。同时保证每个节点的初始相对位置不变。输出重新排列之后的链表。
算法除去输入数据的额外空间复杂度应为O(1)，时间复杂度应为O(nodes)，nodes为节点总数。
输入
第⼀⾏为链表⻓度nodes，第⼆⾏为划分值x，第三⾏为链表中每个节点的数据，每两个数据之间⽤空格隔开。链表中的数据都为 int 类型。
输出
输出重新排列之后的链表，每两个数据之间⽤空格隔开(包括⾏尾的空格)。
*/

#include<iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
};
int main()
{
	int m;
	Node* smaller = NULL;
	Node* larger = NULL;
	Node* shead = NULL;
	Node* lhead = NULL;

	while (cin >> m)
	{
		if (m <= 0)
			return -1;
		int judge(0);
		cin >> judge;

		Node* head = new Node;
		cin >> head->val;
		head->next = NULL;

		if (head->val >= judge)
		{
			//cout<<"larger head"<<endl;
			larger = head;
			lhead = larger;
		}
		else
		{
			//cout<<"smaller head"<<endl;
			smaller = head;
			shead = smaller;
		}



		int i(0);
		for (; i < m - 1; i++)
		{
			Node* now = new Node;
			cin >> now->val;
			now->next = NULL;
			//cout<<now->val<<endl;
			if (now->val >= judge)
			{
				if (larger == NULL)
				{
					//cout<<"larger head"<<endl;
					larger = now;
					lhead = larger;
				}
				else
				{

					larger->next = now;
					larger = larger->next;
				}
			}
			else
			{
				if (smaller == NULL)
				{
					//cout<<"smaller head"<<endl;
					smaller = now;
					shead = smaller;
				}
				else
				{
					smaller->next = now;
					smaller = smaller->next;
				}
			}
		}
		Node* release = NULL;
		if (smaller != NULL)
		{
			release = shead;
			smaller->next = lhead;
			while (shead != NULL)
			{
				cout << shead->val << " ";
				shead = shead->next;
			}
			cout << endl;
			while (release != NULL)
			{
				Node* temp = release;
				release = release->next;
				delete temp;
			}
		}
		else
		{
			release = lhead;
			while (lhead != NULL)
			{
				cout << lhead->val << " ";
				lhead = lhead->next;
			}
			cout << endl;
			while (release != NULL)
			{
				Node* temp = release;
				release = release->next;
				delete temp;
			}
		}

	}

	return 0;
}
