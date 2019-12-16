#include<iostream>
using namespace std;
struct Node{
	int val=-1;
	Node* left=NULL;
	Node* right=NULL;
};
int module2 ()
{
	int number;
	cin>>number;
	Node *head;
	for(int i(0);i<number;i++)
	{
		int mydata;
		cin>>mydata;
		if(head==NULL)
		{
			Node *temp=new Node;
			temp->val=mydata;
			head=temp;
		}
		else
		{
			Node *visit=head;
			while(visit->right!=NULL&&mydata>visit->val)
			{
				visit=visit->right;
			}
			if(visit->right==NULL)
			{
				if(visit->val<mydata)
				{
					Node *temp=new Node;
					temp->right=NULL;
					temp->left=visit;
					visit->right=temp;
				}
			}
		}
	}
}
int main()
{
	module2();
	return 0; 
}
