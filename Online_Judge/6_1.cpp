/*
问题 A: 看漫画
时间限制: 1 Sec  内存限制: 128 MB
提交: 710  解决: 89
[提交][状态][讨论版]
题目描述
小蓝鲸喜欢看漫画，但小蓝鲸的寝室长禁止宿舍内看漫画。小蓝鲸刚借到 N 本漫画，第i本漫画中有 page[i] 页。寝室长有事外出一段时间，并在 T 小时后回来，小蓝鲸希望在这段时间看完这些漫画书。

小蓝鲸可以决定看漫画的速度 S 页/小时。每个小时，她会选择一本漫画，阅读 S 页，若这本漫画少于 S 页，她将看完这本漫画书，然后在这一小时内不会再看其他的漫画书。

因为小蓝鲸习惯慢慢看书，但希望能够在寝室长回来之前看完，所以希望你告诉她在 T 小时内看完所有 N 本书的最小阅读速度 S (S为整数）。
输入
第一行给出两个整数 N(1≤N≤104)，表示漫画书的数量，以及 T(N ≤T≤109)，表示寝室长离开的时间。

第二行给出N个整数，整数之间用空格分开，表示第i本漫画的页数 page[i](1≤page[i]≤109)。

输出
输出一个数字 S，表示在寝室长回来之前小蓝鲸阅读完 N 本漫画书的最慢速度。
样例输入
4 5
4 5 7 13
样例输出
7
*/
#include<iostream>
#include<vector>
using namespace std; 
vector<int>mydata;
int count_time(int j)
{
	int used_time(0);
	for (int i(0); i < mydata.size(); i++)
	{
		used_time += mydata[i] / j;
		if (mydata[i] % j != 0)
		{
			used_time++;
		}
	}
	return used_time;
}

int get_time(int lower, int higher, int given)
{
	if (lower == higher)
	{
		return lower;
	}
	int cur = (lower + higher) / 2;
	if (cur == lower)
	{
		return higher;
	}
	if (given < count_time(cur))
	{
		return get_time(cur, higher, given);
	}
	else
	{
		return get_time(lower, cur, given);
	}
}

int main()
{
	int num(0);
	cin >> num;
	int out_time(0);
	cin >> out_time;
	
	for (int i(0); i < num; i++)
	{
		int temp;
		cin >> temp;
		mydata.push_back(temp);
	}
	int lower(0);
	int higher(0);
	int total(0);
	for (int i(0); i < mydata.size(); i++)
	{
		total += mydata[i];
		if (mydata[i] > higher)
		{
			higher = mydata[i];
		}
	}
	lower = total / out_time;
	cout << get_time(lower, higher, out_time) ;
	return 0;

}