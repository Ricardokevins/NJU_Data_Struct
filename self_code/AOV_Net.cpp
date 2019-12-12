#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
using namespace std;

struct Node{
	Node* next;
	int num;
};
vector<Node*>vex;
vector<int>count_degree;
int vex_num;
int edge_num;

void create_graph()
{
	cin >> vex_num;
	cin >> edge_num;
	for (int i(0); i < vex_num; i++)
	{
		Node* temp = new Node;
		temp->next = NULL;
		temp->num = i;
		vex.push_back(temp);
		count_degree.push_back(0);
	}
	for (int i(0); i < edge_num; i++)
	{
		int a, b;
		cin >> a >> b;
		Node* target = vex[a - 1];
		while (target->next != NULL)
		{
			target = target->next;
		}
		Node* temp2 = new Node;
		temp2->num = b - 1;
		temp2->next = NULL;
		target->next = temp2;
	}
}

void print_graph() {
	int count = 0;
	cout << "graph as below ：" << endl;
	
	for (int i(0); i < vex_num; i++)
	{
		cout << vex[i]->num << " ";
		Node* cur = vex[i]->next;
		while (cur != NULL)
		{
			cout << "<" << vex[i]->num << "," << cur->num << ">   ";
			cur = cur->next;
		}
		cout << endl;
	}

}

int get_by_TuoPu()
{
	cout << "Tuo Pu sort result as followed: " << endl;
	stack<int>node;
	for (int i(0); i < vex_num; i++)
	{
		Node * temp = vex[i]->next;
		while (temp != NULL)
		{
			count_degree[temp->num]++;
			temp = temp->next;
		}
	}
	for (int i(0); i < vex_num; i++)
	{
		if (count_degree[i] == 0)
		{
			node.push(i);
		}
	}
	int count(0);
	while (!node.empty())
	{
		int cur = node.top();
		node.pop();
		cout << vex[cur]->num << " ";
		Node* temp2 = vex[cur]->next;
		while (temp2 != NULL)
		{
			count_degree[temp2->num]--;
			if (count_degree[temp2->num] == 0)
			{
				node.push(temp2->num);
			}
			temp2 = temp2->next;
		}
		count++;
	}
	if (count == vex_num)
	{
		cout << endl;
		return 1;
	}
	else
	{
		cout << "this graph has loop . System Error Hit bad trap" << endl;
		return 0;
	}
}
vector<bool>visit;

void dfs(int n, stack<int>& result) {

	visit[n] = true;
	Node* temp = vex[n]->next;
	while (temp) {
		if (!visit[temp->num]) {
			dfs(temp->num,  result);
		}
		temp = temp->next;
	}
	result.push(vex[n]->num);
}

int get_by_Dfs()
{
	stack<int> path;
	
	for (int i(0); i < vex_num; i++)
	{
		visit.push_back(0);
	}
	cout << "Dfs sort result as follows:" << endl;
	
	for (int i = 0; i <vex_num; i++) {
		if (!visit[i]) {
			dfs(i, path);
		}
	}

	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}

	cout << endl;
	return true;
}


/*
testcase:
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5
*/

int main()
{
	create_graph();
	print_graph();
	get_by_TuoPu();
	cout << endl << endl;
	get_by_Dfs();
	return 0;
}

