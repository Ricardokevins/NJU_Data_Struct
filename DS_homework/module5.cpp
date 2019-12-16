#include<iostream>
using namespace std;
#define maxsize 10000
#define my_max 1000000000
#define my_min -1

int hash_map(int num, int len, int min, int max)
{
	return (int)((num - min) * len / (max - min));
}

int module5()
{
	int number;
	cin >> number;
	int max[maxsize] = { 0 };
	int min[maxsize] = { 0 };
	int has_num[maxsize] = { 0 };
	int mydata[maxsize] = { 0 };
	for (int i(0); i < number; i++)
	{
		cin >> mydata[i];
	}
	int pos(0);
	int max_data = my_min;
	int min_data = my_max;
	for (int i(0); i < number; i++)
	{
		if (mydata[i] < min_data)
		{
			min_data = mydata[i];
		}
		if (mydata[i] > max_data)
		{
			max_data = mydata[i];
		}
	}
	//cout << max_data << "   " << min_data << endl;
	for (int i(0); i < number; i++)
	{
		pos = hash_map(mydata[i], number, min_data, max_data);
		if (has_num[pos])
		{
			if (mydata[i] < min[pos])
			{
				min[pos] = mydata[i];
			}
			if (mydata[i] > max[pos])
			{
				max[pos] = mydata[i];
			}
		}
		else
		{
			min[pos] = mydata[i];
			max[pos] = mydata[i];
			has_num[pos] = 1;
		}
	}
	int res = 0;
	int last_max = max[0];
	for (int i(1); i <= number; i++)
	{
		//last_max = max[i - 1];
		if (has_num[i])
		{
			res = res > min[i] - last_max ? res : min[i] - last_max;
			last_max = max[i];
		}
		
	}
	return res;
}

int main()
{
	cout <<"resutl: "<< module5();
	return 0;
}
