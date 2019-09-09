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
