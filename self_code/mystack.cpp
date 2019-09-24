#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class mystack{
public:
    int data[2000];
    int top;
    bool get_top(int &a);
    bool is_empty();
    bool print_size();
    bool push(int x);
    bool pop(int &x);
    bool print();
    mystack();
};
mystack::mystack()
{
    top=-1;
}
bool mystack::is_empty()
{
    return top==-1;
}
bool mystack::get_top(int &a)
{
    if(top==-1)
        return false;
    a=data[top];
    return true;
}
bool mystack::print_size()
{
    cout<<"current size is : "<< top+1 << endl;
}
bool mystack::push(int x)
{
    if(top>=1999)
    {
        cout<<"The stack is already full!!! "<<endl;
        return false;
    }
    top++;
    data[top]=x;
    return true;
}
bool mystack::pop(int &x)
{
    if(top==-1)
    {
        cout<<"The stack is already empty!!!"<<endl;
        return false;
    }
    x=data[top];
    top--;
    return true;
}
bool mystack::print()
{
    if(top==-1)
    {
        cout<<"The stack is already empty nothing to print"<<endl;
        return false;
    }
    for(int j(top);j>=0;j--)
    {
        cout<<data[j];
        if(j!=0)
        {
            cout<<" ";
        }
        else
        {
            cout<<endl;
        }
    }
    return true;
}
int main()
{
    mystack a;
    int temp(0);
    a.print();
    a.get_top(temp);
    a.pop(temp);
    
    a.push(1);
    a.push(2);
    a.print();
    a.print_size();
    a.pop(temp);
    cout<<"temp"<<temp<<endl;
    a.print_size();
    a.pop(temp);
}
