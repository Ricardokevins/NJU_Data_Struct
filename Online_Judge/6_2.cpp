/*
问题 B: 小蓝鲸的人数
时间限制: 1 Sec  内存限制: 128 MB
提交: 263  解决: 94
[提交][状态][讨论版]
题目描述
开学初，蓝鲸大学的新生来自不同的城市，每个同学都只知道和自己来自同一个城市的同学人数。现在假设我们可以询问一个同学和他来自同一个城市的同学人数（不包括他自己），在询问了部分同学之后（不会重复询问同一位同学），我们想推断蓝鲸大学的新生的最少数目。

输入
一行整数，空格隔开。每个整数代表一次询问结果。询问的人数M满足1≤M≤1000，每次的询问结果N满足0≤N≤999。

输出
输出一个整数，代表蓝鲸大学最少的新生数目。

样例输入
1 1 1 1 10 10 10 0
样例输出
16
提示

两位同学回答了 "1" ，可以假设这两位同学来自同一座城市，假设是南京。


之后回答了 "2" 的同学不会来自南京，否则他们的回答会相互矛盾。


设回答了 "2" 的同学来自上海，此外，还应有另外 2 位同学没有被问到也来自上海。


因此最少的新生人数为 5: 3 位被问到的和 2 位没有被问到的。

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string a;
	getline(cin, a);
	vector<int>data;
	string temp;
	int pos = 0;
	for (int i(0); i < a.size(); i++)
	{
		if (a[i] != ' ')
		{
			temp.push_back(a[i]);
		}
		else
		{
			if (temp.size() == 0)
			{
				continue;
			}
			else
			{
				int num(0);
				num = stoi(temp);
				data.push_back(num);
				temp.clear();
			}
		}

	}
	if (temp.size() != 0)
	{
		int num(0);
		num = stoi(temp);
		data.push_back(num);
		temp.clear();
	}
	vector<int>numbers;
	vector<int>numbers2;
	for (int i(0); i < data.size(); i++)
	{
		int flag(0);
		int pos = -1;
		for (int j(0); j < numbers.size(); j++)
		{
			if (numbers[j] == data[i] && numbers2[j] != 0)
			{
				flag = 1;
				pos = j;
				break;
			}
		}
		if (flag)
		{
			numbers2[pos] -= 1;
		}
		else
		{
			numbers.push_back(data[i]);
			numbers2.push_back(data[i]);
		}
	}
	int result(0);
	for (int i(0); i < numbers.size(); i++)
	{
		result += numbers[i]+1;
	}
	cout << result;
	return result;
}