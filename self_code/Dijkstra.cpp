#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

struct Path
{
	string path = "";
	int val = 0;
	bool visit = false;
};
vector<Path>Dis;
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
		edge[a-1][b-1] = c;
	}
}

void find_minpath(int begin)
{
	for (int i(0); i < vex_num; i++)
	{
		Path a;
		a.path = to_string(begin) + "->" + to_string(i);
		a.val = edge[begin][i];
		Dis.push_back(a);
	}
	int count = 0;
	while (count < vex_num)
	{
		int temp_pos(0);
		int min = INT_MAX;
		for (int i(0); i < vex_num; i++)
		{
			if (!Dis[i].visit && Dis[i].val < min)
			{
				temp_pos = i;
				min = Dis[i].val;
			}
		}
		Dis[temp_pos].visit = true;
		count++;
		for (int i(0); i < vex_num; i++)
		{
			if (!Dis[i].visit && edge[temp_pos][i] != INT_MAX)
			{
				if (Dis[temp_pos].val + edge[temp_pos][i] < Dis[i].val)
				{
					Dis[i].val = Dis[temp_pos].val + edge[temp_pos][i];
					Dis[i].path = Dis[temp_pos].path + "->" + to_string(i);
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
		if (Dis[i].val == INT_MAX)
		{
			cout << setw(10)<<Dis[i].path << "  " << "no way to get there!" << endl;
		}
		else
		{
			cout << setw(10) << Dis[i].path << "  " << to_string(Dis[i].val) << endl;
		}
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
6 8
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 6 60
5 4 20
*/
int main()
{
	cout.setf(std::ios::left);
	creat_graph();
	print_graph();
	find_minpath(0);
	print_path(0);
	return 0;
}