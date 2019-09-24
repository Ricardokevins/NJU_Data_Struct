#include<iostream>
#include<vector>
using namespace std;
class myqueue{
public:
    int data[3];
    int head;
    int tail;
    int maxsize;
    int cur_size;
    bool is_empty();
    bool is_full();
    bool in_queue(int x);
    bool de_queue(int& x);
    bool print_queue();
    bool print_status(); 
    myqueue();
};
myqueue::myqueue()
{
    head=0;
    tail=0;
    maxsize=3;
    cur_size=0;
}
bool myqueue::is_empty()
{
    return tail==head;
}
bool myqueue::is_full()
{
    return (tail+1)%maxsize==head;
}
bool myqueue::in_queue(int x)
{
    if(is_full())
    {
        cout<<"This queue is already full. Fail to in_queue"<<endl;
        return false;
    }
    data[tail]=x;
    tail=(tail+1)%maxsize;
    cur_size++;
    return true;
}
bool myqueue::de_queue(int &x)
{
    if(is_empty())
    {
        cout<<"This queue is already empty. Fail to de_queue"<<endl;
        return false;
    }
    x=data[head];
    head=(head+1)%maxsize;
    cur_size--;
    return true;
}
bool myqueue::print_queue()
{
    if(is_empty())
    {
        cout<<"This queue is already empty. Fail to print anything"<<endl;
        return false;
    }
    int i=head;
    while(i!=tail)
    {
    	cout<<data[i]<<" ";
    	i++;
    	i=i%maxsize;
	}
    cout<<endl;
}
bool myqueue::print_status()
{
	cout<<"head  "<<head<<"  "<<"tail  "<<tail<<"   "<<"cur_size  "<<cur_size<<endl;
	cout<<data[0]<<" "<<data[1]<<" "<<data[2]<<endl;
	return true;
}  
int main()
{
    myqueue a;
    int temp(0);
    /*
    cout<<"test stage 1"<<endl;
    a.in_queue(1);
    a.print_queue();
    a.print_status();
    a.de_queue(temp);
    a.print_status();
    cout<<"temp  "<<temp<<endl;
	cout<<endl<<endl;

    cout<<"test stage 2"<<endl;
    a.in_queue(1);
    a.print_status();
    a.in_queue(2);
    a.print_status();
    a.in_queue(3);
    a.print_status();
    a.print_queue();
	cout<<endl<<endl;
	
    cout<<"test stage 3"<<endl;
    a.de_queue(temp);
    a.print_status();
    cout<<"temp  "<<temp<<endl;
    a.in_queue(5);
    a.print_status();
    a.print_queue();
    */
    cout<<"final test stage "<<endl;
    a.in_queue(1);
    a.print_queue();
    a.in_queue(2);
    a.print_queue();
    a.in_queue(3);
    a.print_queue();
    a.de_queue(temp);
    cout<<"temp  "<<temp<<endl;
    a.print_queue();
    a.de_queue(temp);
    cout<<"temp  "<<temp<<endl;
    a.print_queue();
    a.de_queue(temp);
    cout<<"temp  "<<temp<<endl;
    a.print_queue();
    a.de_queue(temp);
    cout<<"temp  "<<temp<<endl;
    a.print_queue();
    a.in_queue(8);
    a.print_queue();
    a.de_queue(temp);
    cout<<"temp  "<<temp<<endl;
    a.print_queue();
	cout<<endl<<endl;
	
}
