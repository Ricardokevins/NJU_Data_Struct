#include<iostream>
using namespace std;
#define max_size 1000
int result[max_size] = { 0 };
int number, k;

int change_num(string a)
{
	int num(0);
	int flag(0);
	if (a.size() == 0)
		return num;
	if (a[0] == '-')
	{
		flag = 1;
		a.erase(a.begin());
	}
	while (a.size() != 0)
	{
		num = num * 10;
		num += a[0] - '0';
		a.erase(a.begin());
	}
	if (flag)
		num = -num;
	return num;
}

int print_result()
{
	cout << "result: ";
	for (int i(k - 1); i >= 0; i--)
	{
		if (result[i] != 0)
		{
			cout << result[i] << " ";
		}
		else
		{
			cout << endl;
			return 0;
		}
	}
	cout << endl;
	return 0;
}

int find_pos(int left, int right, int mydata)
{
	if (left == right)
	{
		return left;
	}
	int mid = (left + right) / 2;
	if (left == mid)
	{
		if (result[right] > mydata)
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	if (result[mid] > mydata)
	{
		return find_pos(left, mid, mydata);
	}
	else
	{
		return find_pos(mid, right, mydata);
	}
}

int insert_data(int p)
{

	int pos = find_pos(0,k-1,p);
	//cout << "POS is here" << pos << endl;
	for (int i(0); i < pos  && i < k - 1; i++)
	{
		if (result[i + 1] != 0)
		{
			result[i] = result[i + 1];
		}
	}
	result[pos] = p;
	//cout << "Let us see result: ";
	//for (int i(0); i < k; i++)
	//{
	//	cout << result[i] << " ";
	//}
	//cout << endl;
	return 0;
}

int module3()
{
	cin >> number >> k;
	int count = 0;
	while (count < number)
	{
		string a;
		cin >> a;
		if (a == "Check")
		{
			print_result();
		}
		else
		{
			int temp_data = change_num(a);
			if (temp_data > result[0])
			{
				insert_data(change_num(a));
			}
			count++;
		}
	}
	return 0;
}

int main()
{
	module3();
	return 0;

}