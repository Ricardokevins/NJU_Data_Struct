#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node();
};
class myList {
public:
	Node* head;
	myList();
	bool insert_pos(int pos, int value);
	bool delete_pos(int pos);
	bool print_list();
	bool is_empty();
	bool get_size();
	bool reverse();
	bool sort_list();
	bool sort_list_pro();
    	bool divide_list(int x);
    	Node* merge_list(Node *a,Node*b);
};
Node::Node() {
	val = 0;
	next = NULL;
}
myList::myList() {
	head = new Node;
}
bool myList::insert_pos(int pos, int value) {
	Node* temp = head;
	if (pos < 0)
		return false;
	while (temp != NULL && pos > 0) {
		temp = temp->next;
		pos--;
	}
	if (pos > 0) {
		cout << "List is too short to insert" << endl;
		return false;
	}
	else {
		Node* hh = new Node;
		hh->val = value;
		hh->next = temp->next;
		temp->next = hh;
		return true;
	}
	return false;
}
bool myList::delete_pos(int pos) {
	Node* temp = head;
	if (pos < 0)
		return false;
	while (temp != NULL && pos > 0) {
		temp = temp->next;
		pos--;
	}
	if (pos > 0) {
		cout << "List is too short to delete" << endl;
		return false;
	}
	else {
		Node* hh = temp->next;
		temp->next = hh->next;
		delete hh;
		return true;
	}
	return false;
}
bool myList::print_list() {
	Node* temp = head->next;
	if (head == NULL) {
		return false;
	}
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
	return true;
}
bool myList::is_empty() {
	return head == NULL;
}
bool myList::get_size() {
	int size = -1;
	Node* temp=head;
	while (temp != NULL) {
		temp = temp->next;
		size++;
	}
	cout << "size is " << size << endl;
	return true;
}
bool myList::reverse() {
	Node* p1 = NULL;
	Node* p2 = head->next;
	Node* p3 = p2;

	while (p2) {
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = p1;
	return true;
}
bool myList::sort_list() {
	vector<int> res;
	if (head == NULL) {
		cout << "list is empty fail to sort" << endl;
		return false;
	}
	Node* temp = head->next;
	if (temp == NULL) {
		cout << "list is empty fail to sort" << endl;
		return false;
	}
	while (temp != NULL) {
		res.push_back(temp->val);
		temp = temp->next;
	}
	sort(res.begin(), res.end());
	temp = head->next;
	int i(0);
	while (temp != NULL) {
		temp->val = res[i];
		i++;
		temp = temp->next;
	}
	return true;
}

bool myList::divide_list(int x)
{
        Node *cur=head->next;
        Node *shead=NULL;
        Node*bhead=NULL;
        Node *stail=NULL;
        Node*btail=NULL;
        if(head->next==NULL)
            return head;
        if(head->next->next==NULL)
            return head;
        if(head->next->val<x)
        {
            cout<<"find small head"<<endl;
            shead=head->next;
            stail=head->next;     
        }
        else
        {
            cout<<"find big head"<<endl;
            bhead=head->next;
            btail=head->next;
        }
        cur=head->next->next;
        while(cur!=NULL)
        {
            cout<<cur->val<<endl;
            if(cur->val<x)
            {
                if(shead==NULL)
                {
                    cout<<"append small head"<<endl;
                    shead=cur;
                    stail=cur;
                }
                else
                {
                    cout<<"append small tail"<<endl;
                    stail->next=cur;
                    stail=stail->next;
                }
            }
            else
            {
                if(bhead==NULL)
                {
                    cout<<"append big head"<<endl;
                    bhead=cur;
                    btail=cur;
                }
                else
                {
                    cout<<"append big tail"<<endl;
                    btail->next=cur;
                    btail=btail->next;
                }
            }
            cur=cur->next;
        }
        if(shead==NULL)
        {
            btail->next=NULL;
            head->next=bhead;
            return true;
        }
        if(bhead==NULL)
        {
            stail->next=NULL;
            head->next= shead;
            return true;
        }
        stail->next=bhead;
        btail->next=NULL;
        cout<<"ex over"<<endl;
        head->next= shead;
        return true;
}

Node *myList::merge_list(Node *l1,Node*l2)
{
        Node *res;
        Node *temp;
        if(l2==NULL)
            return l1;
        if(l1==NULL)
            return l2;
        if(l1->val<l2->val)
        {
            cout<<"initial l1 bigger"<<l1->val;
            res=l1;
            l1=l1->next;
            temp=res;
        }
        else
        {
            cout<<"initial l2 bigger"<<l2->val;
            res=l2;
            l2=l2->next;
            temp=res;
        }
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                cout<<" l1 bigger"<<l1->val;
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else
            {
                cout<<" l2 bigger"<<l2->val;
                temp->next=l2;
                l2=l2->next;
                
                temp=temp->next;
            }
        }
        if(l1==NULL)
        {
            temp->next=l2;
            return res;
        }
        if(l2==NULL)
        {
            temp->next=l1;
            return res;
        }
        return res;
}
//bool mysort1(vector<int>& a);
//bool mysort2(vector<int>& a);
int main() {

	myList a;
	a.insert_pos(0, 2);
	a.insert_pos(1, 1);
	a.insert_pos(2, 4);
	a.insert_pos(3, -2);
	a.insert_pos(3, 0);
	//a.print_list();
	//a.reverse();
	a.print_list();
	//a.sort_list();
	a.sort_list_pro();
	a.print_list();
	//a.delete_pos(1);
	//a.delete_pos(0);
	//a.print_list();
	return 0;

	/*
	vector<int> a;
	a.push_back(1);
	a.push_back(9);
	a.push_back(7);
	a.push_back(3);
	a.push_back(2);
	for(int j(0);j<a.size();j++)
	{
		cout<<a[j]<<" ";
	}
	cout<<endl;
	mysort2(a);
	for(int j(0);j<a.size();j++)
	{
		cout<<a[j]<<" ";
	}
	*/

}
/*
ListNode* sortList(ListNode* head) {
		return mergesort(head);
	}
	ListNode* mergesort(ListNode* node)
	{
		if(!node || !node->next) return node;
		ListNode *fast=node;//快指针走两步
		ListNode *slow=node;//慢指针走一步
		ListNode *brek=node;//断点
		while(fast && fast->next)
		{
			fast=fast->next->next;
			brek=slow;
			slow=slow->next;
		}
		brek->next=nullptr;
		ListNode *l1=mergesort(node);
		ListNode *l2=mergesort(slow);
		return merge(l1,l2);
	}
	ListNode* merge(ListNode* l1,ListNode* l2)
	{
		if(l1==NULL)
		{
			return l2;
		}
		if(l2==NULL)
		{
			return l1;
		}
		if(l1->val < l2->val)
		{
			l1->next=merge(l1->next,l2);
			return l1;
		}
		else
		{
			l2->next=merge(l2->next,l1);
			return l2;
		}
	}
这种链表排序的方案使用的是递归
*/

/*
上述的方案是vector直接调用库函数进行排序，为了复习一下排序决定自己写一下

bool mysort1(vector<int>& a)
{
	for(int i(0);i<a.size();i++)
	{
		int min=a[i];
		int pos(0);
		for(int j(i+1);j<a.size();j++)
		{
			if(a[j]<min)
			{
				pos=j;
				min=a[j];
			}
		}
		if(pos!=0)
		{
			int temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
	return true;
}
bool mysort2(vector<int>&a)
{
	for(int i(0);i<a.size();i++)
	{
		for(int j(0);j<a.size()-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	return false;
}
*/


/*
最后的最后我决定自己再实现一个基于交换节点的排序
*/
bool myList::sort_list_pro()
{
	if (head->next == NULL)
		return false;
	if (head->next->next == NULL)
		return false;
	Node* temp = head->next;
	Node* temp2 = temp->next;
	temp->next = NULL;
	while (temp2 != NULL)
	{
		Node* gogogo = head;
		while (gogogo != temp && gogogo->next != NULL && gogogo->next->val <= temp2->val)
		{
			gogogo = gogogo->next;
		}
		if (gogogo == temp)
		{			
			temp->next=temp2;
			temp = temp->next;
			//cout << "expand   " << endl;
			temp2 = temp2->next;
			temp->next = NULL;
		
		}
		else
		{
			//cout << "exchange   " << endl;
			Node* kkk = temp2;
			temp2 = temp2->next;
			kkk->next = gogogo->next;
			gogogo->next = kkk;
		}
	}
	return true;
}
