#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node();
}; 
class myList{
public:
    Node* head;
    myList();
    bool insert_pos(int pos,int value);
    bool delete_pos(int pos);
    bool print_list();
    bool is_empty();
    bool get_size();
    bool reverse();
};

Node::Node()
{
    val=0;
    next=NULL;
}
myList::myList()
{
    head=new Node;
}
bool myList::insert_pos(int pos,int value)
{
    Node *temp=head;
    if(pos<0)
        return false;
    while(temp!=NULL&&pos>0)
    {
        temp=temp->next;
        pos--;
    }
    if(pos>0)
    {
        cout<<"List is too short to insert"<<endl;
        return false;
    }
    else
    {
        Node *hh=new Node;
        hh->val=value;
        hh->next=temp->next;
        temp->next=hh;
        return true;
    }
    return false;
}
bool myList::delete_pos(int pos)
{
    Node *temp=head;
    if(pos<0)
        return false;
    while(temp!=NULL&&pos>0)
    {
        temp=temp->next;
        pos--;
    }
    if(pos>0)
    {
        cout<<"List is too short to delete"<<endl;
        return false;
    }
    else
    {
        Node *hh=temp->next;
        temp->next=hh->next;
        delete hh;
        return true;
    }
    return false;
}
bool myList::print_list()
{
    Node *temp=head;
    if(head==NULL)
    {
        return false;
    }
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return true;
}
bool myList::is_empty()
{
    return head==NULL;
}
bool myList::get_size()
{
    int size=-1;
    Node *temp;
    while(temp!=NULL)
    {
        temp=temp->next;
        size++;
    }
    cout<<"size is "<<size<<endl;
    return true;
}
bool myList::reverse()
{
	Node *p1 = NULL;
	Node *p2 = head;
    Node *p3 = p2;
        
    while(p2)
	{
    	p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;            
    }
    head =  p1;
 } 
int main()
{
    myList a;
    a.is_empty();
    a.insert_pos(0,1);
    
    a.insert_pos(1,2);
    a.print_list();
    a.reverse();
	a.print_list();
    return 0;
}
