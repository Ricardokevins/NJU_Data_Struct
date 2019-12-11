#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

vector<vector<int>>path;
vector<vector<int>>edge;

int vex_num;
int edge_num;

void creat_graph()
{
	cin >> vex_num;
	cin >> edge_num;
	vector<int>temp;
	vector<int>temp2;
	for (int i(0); i < vex_num; i++)
	{
		temp.push_back(INT_MAX);
		temp2.push_back(i);
	}
	for (int i(0); i < vex_num; i++)
	{
		edge.push_back(temp);
		path.push_back(temp2);
	}
	for (int i(0); i < edge_num; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a - 1][b - 1] = c;
		edge[b - 1][a - 1] = c;
	}
}

void Floyd()
{
	int temp = 0;
	int select = 0;
	for (int i(0); i < vex_num; i++)
	{
		for (int j(0); j < vex_num; j++)
		{
			for (int k(0); k < vex_num; k++)
			{
				select = (edge[j][i] == INT_MAX || edge[i][k] == INT_MAX)?INT_MAX:(edge[j][i]+edge[i][k]);
				if (edge[j][k] > select)
				{
					edge[j][k] = select;
					path[j][k] = path[j][i];
				}
			}
		}
	}
}

void print_path(int begin)
{
	cout << "The shortest path is:" << endl;
	for (int i(0); i < vex_num; i++)
	{
		for (int j = i + 1; j < vex_num; j++)
		{
			cout << to_string(i) << "---" << to_string(j) << "value: " << edge[i][j] << "  path: " << to_string(i);
			int temp = path[i][j];
			while (temp != j)
			{
				cout << "--->" << to_string(temp);
				temp =path[temp][j];
			}
			cout << "--->" << to_string(j) << endl;
		}
		cout << endl;
	}
}

void print_graph()
{
	for (int i(0); i < vex_num; i++)
	{
		for (int j(0); j < vex_num; j++)
		{
			if (edge[i][j] != INT_MAX)
			{
				cout << setw(10) << edge[i][j] << " ";
			}
			else
			{
				cout << setw(10) << "∞" << " ";
			}
		}
		cout << endl;
	}
}

/*
testcase:
7 12
1 2 12
1 6 16
1 7 14
2 3 10
2 6 7
3 4 3
3 5 5
3 6 6
4 5 4
5 6 2
5 7 8
6 7 9
*/
int main()
{
	cout.setf(std::ios::left);
	creat_graph();
	print_graph();
	Floyd();
	print_graph();
	print_path(0);
	return 0;
}