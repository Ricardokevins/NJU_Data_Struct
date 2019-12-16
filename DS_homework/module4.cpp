#include<iostream>
#include<string>
using namespace std;

#define max_size 10000
struct Node {
	string data = "";
	Node* next = NULL;
};

Node my_data[max_size];

int hash_map(string a)
{
	int hash_num(0);
	for (int i(0); i < a.size(); i++)
	{
		if (a[i] <='9'&&a[i]>='0')
		{
			hash_num += a[i] - '0';
		}
		else
		{		
			hash_num += 0;
		}
	}
	return (hash_num % 10000);
}

int module4()
{
	int num1, num2;
	cin >> num1 >> num2;
	for (int i(0); i < num1; i++)
	{
		string temp;
		cin >> temp;
		int pos = hash_map(temp);
		if (my_data[pos].data == "")
		{
			my_data[pos].data = temp;
		}
		else
		{
			Node* cur = &my_data[pos];
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			Node* hh = new Node;
			hh->data = temp;
			hh->next = NULL;
			cur->next = hh;
		}
	}
	for (int i(0); i < num2; i++)
	{
		string temp;
		cin >> temp;
		int pos = hash_map(temp);
		if (my_data[pos].data == "")
			cout << "false" << endl;
		else
		{
			Node* cur = &my_data[pos];
			while (cur->next != NULL&&cur->data!=temp)
			{
				cur = cur->next;
			}
			if (cur->data == temp)
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
		}
	}
	return 0;
}

int main()
{
	module4();
	return 0;
}