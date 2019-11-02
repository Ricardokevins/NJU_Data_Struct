//输入边序列，然后求无向多叉树的直径
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	struct Node {
		int val;
		int fa_val;
		vector<Node*>child;
	};

	int visit(Node* root)
	{
		if (root == NULL)
			return 1;
		cout << root->val << endl;
		for (int i(0); i < root->child.size(); i++)
		{
			visit(root->child[i]);
		}
		return 1;
	}
	int dfs(Node* a, int& dis)
	{
		int max(0);
		int submax(0);
		for (int i(0); i < a->child.size(); i++)
		{
			int num = (dfs(a->child[i], dis));
			if (num >= submax)
			{
				if (num >= max)
				{
					submax = max;
					max = num;
				}
				else
				{
					submax = num;
				}
			}
		}
		//cout << "find" << a->val << "   " << max << "  " << submax  << dis << endl;
		dis = submax + max > dis ? submax + max : dis;
		return max + 1;

	}
	int count(Node* a)
	{
		int diameter(0);
		dfs(a, diameter);
		return diameter;
	}
	int build(Node* root, vector<vector<int>>& edge)
	{
		int num = root->val;
		for (int i(0); i < edge.size(); i++)
		{
			if (edge[i][0] == num || edge[i][1] == num && edge[i][1] != root->fa_val && edge[i][0] != root->fa_val)
			{
				if (num == edge[i][0])
				{
					Node* temp = new Node;
					temp->val = edge[i][1];
					temp->fa_val = num;
					root->child.push_back(temp);
					build(temp, edge);
				}
				else
				{
					Node* temp = new Node;
					temp->val = edge[i][0];
					temp->fa_val = num;
					root->child.push_back(temp);
					build(temp, edge);
				}
			}
		}
		return 0;
	}
	int treeDiameter(vector<vector<int>>& edges) {
		if (edges.size() == 0)
		{
			return 0;
		}
		Node* root = new Node;
		root->val = edges[0][0];
		root->fa_val = -1;
		build(root, edges);
		visit(root);
		return count(root);

	}
};
//[[0,1],[1,2],[2,3],[1,4],[4,5],[0,6],[0,7],[7,8]]

int main()
{
	vector<vector<int>>test;
	vector<int>temp;
	temp.push_back(0);
	temp.push_back(1);
	test.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(2);
	test.push_back(temp);
	temp.clear();
	temp.push_back(2);
	temp.push_back(3);
	test.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(4);
	test.push_back(temp);
	temp.clear();
	temp.push_back(4);
	temp.push_back(5);
	test.push_back(temp);
	temp.clear();
	temp.push_back(0);
	temp.push_back(6);
	test.push_back(temp);
	temp.clear();
	temp.push_back(0);
	temp.push_back(7);
	test.push_back(temp);
	temp.clear();
	temp.push_back(7);
	temp.push_back(8);
	test.push_back(temp);
	temp.clear();
	Solution a;

	cout<<a.treeDiameter(test);
	return 0;
}
