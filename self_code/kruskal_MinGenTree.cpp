#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct edge_tag {
	bool visit;
	int start;
	int end;
	int weight;
};

int vex_num;
int edge_num;

vector<edge_tag> Edge;

void create_graph()
{
	cin >> vex_num;
	cin >> edge_num;
	for (int i(0); i < edge_num; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge_tag temp;
		temp.start = a-1;
		temp.end = b-1;
		temp.weight = c;
		temp.visit = false;
		Edge.push_back(temp);
	}
}

int cmp(const edge_tag first, const edge_tag second) {
	return first.weight < second.weight;
}
vector<int>myparent;
vector<int>mychild;

int find_root(int child) {
	if (myparent[child] == child) {
		return child;
	}	
	myparent[child] = find_root(myparent[child]);
	return myparent[child];
}

bool union_tree(edge_tag  e) {
	
	int root1;
	int root2;
	
	root1 = find_root(e.start);
	root2 = find_root(e.end);
	
	if (root1 != root2) 
	{	
		if (mychild[root1] > mychild[root2])
		{
			myparent[root2] = root1;		
			mychild[root1] += mychild[root2] + 1;
		}
		else 
		{
			myparent[root1] = root2;
			mychild[root2] += mychild[root1] + 1;
		}
		return true;
	}
	return false;
}

void kruskal()
{
	int total_cost(0);
	for (int i(0); i < vex_num; i++)
	{
		myparent.push_back(i);
		mychild.push_back(0);
	}
	sort(Edge.begin(), Edge.end(), cmp);
	int count(0);
	for (int i(0); i < edge_num; i++)
	{
		if (union_tree(Edge[i])) {
			cout << ("v" + std::to_string(Edge[i].start))
				<< "-----"
				<< ("v" + std::to_string(Edge[i].end))
				<< "="
				<< Edge[i].weight
				<< endl;
			Edge[i].visit = true;
			total_cost += Edge[i].weight;
			++count; 
		}
		
		if (count == vex_num - 1) {
			break;
		}
	}
	if (count != vex_num - 1) {
		cout << "the graph contains some dot disconnect! Error! " << endl;
	}
	else
	{
		cout << "total cost: " << total_cost << endl;
	}

}

int main()
{
	create_graph();
	kruskal();
	return 0;
}