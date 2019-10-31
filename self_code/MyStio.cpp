#include<string>
#include<iostream>
using namespace std;
int change_num(string a)
{
	int num(0);
	int flag(0);
	if(a.size()==0)
		return num;
	if(a[0]=='-')
	{
		flag=1;
		a.erase(a.begin());
	}
	while (a.size() != 0)
	{
		num = num * 10;
		num += a[0] - '0';
		a.erase(a.begin());
	}
	if(flag)
		num=-num;
	return num;
}
int main()
{
	string a;
	cin>>a;
	cout<<change_num(a);
	return 0;
 } 
