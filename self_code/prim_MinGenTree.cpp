#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
using namespace std;


struct Node {
	int start;
	int end;  
	int weight;  
};
vector<vector<int>>edge;
int vex_num;
int edge_num;

void creat_graph()
{
	cin >> vex_num;
	cin >> edge_num;
	vector<int>temp;
	for (int i(0); i < vex_num; i++)
	{
		temp.push_back(INT_MAX);
	}
	for (int i(0); i < vex_num; i++)
	{
		edge.push_back(temp);
	}
	for (int i(0); i < edge_num; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a - 1][b - 1] = c;
		edge[b - 1][a - 1] = c;
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

vector<Node>short_edge;

void prim(int start)
{
	int total_cost = 0;
	for (int i(0); i < vex_num; i++)
	{

		Node  temp;
		temp.start = start;
		temp.end = i;
		temp.weight = edge[start][i];
		short_edge.push_back(temp);
	}
	
	short_edge[start].weight = -1;
	for (int i(1); i < vex_num; i++)
	{
		int min = INT_MAX;
		int min_pos = 0;
		for (int j(0); j < vex_num; j++)
		{
			if (short_edge[j].weight != -1)
			{
				if (short_edge[j].weight < min)
				{
					min = short_edge[j].weight;
					min_pos = j;

				}
			}
		}
		short_edge[min_pos].weight = -1;
		cout << to_string(short_edge[min_pos].start) << "--->" << to_string(short_edge[min_pos].end) << endl;
		total_cost += edge[short_edge[min_pos].start][short_edge[min_pos].end];
		for (int j(0); j < vex_num; j++)
		{
			if (edge[min_pos][j] < short_edge[j].weight)
			{
				short_edge[j].weight = edge[min_pos][j];
				short_edge[j].start = min_pos;
				short_edge[j].end = j;
			}
		}
	}
	cout << "total cost is :  "<<total_cost << endl;
}



/*
testcase:
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 5 6
3 6 4
4 3 5
4 6 2
5 6 6
*/

int main()
{
	creat_graph();
	print_graph();
	cout << endl << endl;
	prim(0);
	return 0;
}

