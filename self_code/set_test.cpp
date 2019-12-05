#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
     s.insert(2);
    cout<<s.size()<<endl;
    set<int>::iterator iter=s.begin(); set<int>::iterator iter2=s.begin(); 
    cout<<*(iter++)<<endl;
    cout<<*(iter++)<<endl;
    cout<<*(iter++)<<endl;
    cout<<*(iter++)<<endl;
    iter=s.find(3);
    cout<<*(iter)<<endl;
    iter2=s.find(12);
    cout<<*(iter)<<endl;
    if(iter!=iter2)
    {
    	cout<<"no"<<endl;
	}
	else
	{
		cout<<"yes"<<endl;
	}
	if(iter2!=s.end())
    {
    	cout<<"no"<<endl;
	}
	else
	{
		cout<<"yes"<<endl;
	}
    return 0;
    
}
