/*
题目描述
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。注意时间复杂度。说明：你不能倾斜容器，且 n 的值至少为 2。



输入
输入包括两行，第一行为非负整数的个数n(0<n<=1000000);

第二行依次输入n个整数，中间用空格隔开。

输出
输出容纳水的最大值。图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
*/

#include<iostream>
using namespace std;


long long int mymax(long long int m, long long int n)
{
	if (m > n)
	{
		return m;
	}
	else
		return n;
}
long long int mymin(long long int m, long long int n)
{
	if (m > n)
	{
		return n;
	}
	else
		return m;
}

int main()
{
	int m(0);
	while (cin >> m)
	{
		int* s = new int[m];
		for (int j(0); j < m; j++)
		{
			cin >> s[j];
		}
		long long int left = 0;
		long long int right = m - 1;
		long long int res = 0;
		while (left < right)
		{
			res = mymax(res, (mymin(s[left], s[right]) * (right - left)));
			if (s[left] < s[right])
			{
				left++;
			}
			else
				right--;
		}
		cout << res << endl;
		delete[]s;
	}
	return 0;
}
