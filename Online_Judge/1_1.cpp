/*
题目描述
P85，2.12 设有两个整数类型的顺序表A(有m个元素）和B(有n个元素），其元素均以从小到大的升序排列。试将这两个顺序表合并成一个顺序表C，要求C的元素也以从小到大的升序排列。（请尽量简化算法复杂度）（m和n不为0）

输入
输入多组数据，每组格式如下

m n

A

B

其中m,n 分别表示顺序表A和B的元素个数，A、B为顺序表元素
*/
#include<iostream>
using namespace std;
int main()
{
	int a=0;
	int b=0;
	while (cin >> a >> b)
	{
		int* s1 = new int[a];
		int* s2 = new int[b];
		int* res = new int[a + b];
		for (int i=0; i < a; i++)
		{
			cin >> s1[i];
		}
		for (int i=0; i < b; i++)
		{
			cin >> s2[i];
		}
		int i=0;
		int j=0;
		for (; i < a&&j<b;)
		{		
				if (s1[i] < s2[j])
				{
					res[i + j] = s1[i];
					i++;
				}
				else
				{
					res[i + j] = s2[j];
					j++;
				}	
		}
		if (i == a)
		{
			for (; j < b; j++)
			{
				res[i + j] = s2[j];
			}
		}
		if (j == b)
		{
			for (; i < a;i++)
			{
				res[i + j] = s1[i];
			}
		}
		for (int j=0; j < a + b; j++)
		{
			cout << res[j];
			if (j != a + b - 1)
			{
				cout << " ";
			}
			else
			{
				cout << endl;
			}
		}
		delete []s1;
		delete []s2;
		delete []res;
	}
	return 0;
}
