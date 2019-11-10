/*
问题 C: 生成hash表
时间限制: 1 Sec  内存限制: 128 MB
提交: 289  解决: 78
[提交][状态][讨论版]
题目描述
编写一个算法，顺序输出hash表内容。设散列函数为 hash(x) = x 中 的第一个数字，采用线性探查法来解决冲突。(hash表的size请设置大于30)

输入
多组输入，每组输入有两行

第一行为数字n，表示有n个整数（多位），n不大于20

第二行为n个以空格相隔的整数

输出
顺序输出hash表的内容

样例输入
5
1 12 11 24 26
样例输出
1,12,11,24,26
提示
*/

#include<iostream>
#include<vector>
using namespace std;
#define hash_size 100

int hash_count(int m)
{
	int num(0);
	while (m != 0)
	{
		num = m % 10;
		m = m / 10;
	}
	return num;
}
int main()
{
	int num(0);
	while (cin >> num)
	{
		int hash_dataset[hash_size] = { 0 };
		vector<int>my_data;
		for (int i(0); i < num; i++)
		{
			int temp(0);
			cin >> temp;
			my_data.push_back(temp);
		}
		for (int i(0); i < my_data.size(); i++)
		{
			int pos = hash_count(my_data[i]);
			pos = pos % hash_size;
			while (hash_dataset[pos] != 0)
			{
				pos = pos + 1;
				pos = pos % hash_size;
			}
			hash_dataset[pos] = my_data[i];
		}
		vector<int>result;
		for (int i(0); i < hash_size; i++)
		{
			if (hash_dataset[i] != 0)
			{
				result.push_back(hash_dataset[i]);
			}
		}
		for (int i(0); i < result.size(); i++)
		{
			cout << result[i];
			if (i != result.size() - 1)
				cout << ",";
		}
		cout << endl;
	}
	return 0;
}
