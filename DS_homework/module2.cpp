#include<iostream>
#include <cassert>
using namespace std;

struct Node {
	int val = -1;
	Node* left = NULL;
	Node* right = NULL;
	int time = 1;
	int left_child_num = 0;
	int right_child_num = 0;
};

int total_num(0);

//use visit function to test build function complete
int test_visit(Node* p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		test_visit(p->left);
		cout << "testval:  " << p->val << "   testtime  " << p->time << "   testleftnum: " << p->left_child_num << "   testrightnum  " << p->right_child_num << endl;
		test_visit(p->right);
	}
	return 0;
}

int test_simpler_test(Node* p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		test_simpler_test(p->left);
		for (int i(0); i < p->time; i++)
		{
			cout << p->val << " ";
		}
		test_simpler_test(p->right);
	}
	
	return 0;
}

//perform bad in some case
Node* build(int p, Node* q)
{
	if (q == NULL)
	{
		assert(0);//Hit bad trap here
	}
	if (q->val == p)
	{
		q->time++;
		return q;
	}
	if (q->val > p)
	{
		q->left_child_num++;
		if (q->left == NULL)
		{
			Node* temp = new Node;
			temp->time = 1;
			temp->left_child_num = 0;
			temp->right_child_num = 0;
			temp->val = p;
			q->left = temp;
			return NULL;
		}
		else
		{
			build(p, q->left);
		}
	}
	else
	{
		q->right_child_num++;
		if (q->right == NULL)
		{
			Node* temp = new Node;
			temp->time = 1;
			temp->left_child_num = 0;
			temp->right_child_num = 0;
			temp->val = p;
			q->right = temp;
			return NULL;
		}
		else
		{
			build(p, q->right);
		}
	}
	return NULL;
}


Node* build2(int p, Node* q)
{
	if (q == NULL)
	{
		assert(0);//Hit bad trap here
	}
	//if (q->val == p)
	//{
	//	q->time++;
	///	return q;
	//}
	if (q->val >= p)
	{
		q->left_child_num++;
		if (q->left == NULL)
		{
			Node* temp = new Node;
			temp->time = 1;
			temp->left_child_num = 0;
			temp->right_child_num = 0;
			temp->val = p;
			q->left = temp;
			return NULL;
		}
		else
		{
			build(p, q->left);
		}
	}
	else
	{
		q->right_child_num++;
		if (q->right == NULL)
		{
			Node* temp = new Node;
			temp->time = 1;
			temp->left_child_num = 0;
			temp->right_child_num = 0;
			temp->val = p;
			q->right = temp;
			return NULL;
		}
		else
		{
			build(p, q->right);
		}
	}
	return NULL;
}

int already_travel = 0;
/*
int get_min_num(Node* p)
{
	if (p == NULL)
		return 0;
	while (p->left != NULL)
	{
		p = p->left;
	}
	return p->val;
}

int get_mid_num(Node* p)
{
	if (p == NULL)
		return 0;
	if (total_num % 2 == 1&&total_num+1/2>=already_travel&& total_num + 1 / 2<=already_travel+p->time)
	{
		return p->val;
	}
	if (total_num % 2 == 0 )
	{
		if (total_num / 2 >= already_travel && total_num / 2 <= already_travel + p->time)
		{
			if (p->time == 1)
			{
				int result = p->val + get_min_num(p->left);
				return result / 2;
			}
			else
			{
				return p->val;
			}
		}
	}
	if (p->left == NULL)
	{
		already_travel++;
		return get_mid_num(p->right);
	}
	if (p->right == NULL)
	{
		already_travel++;
		return get_mid_num(p->left);
	}
	if (p->left_child_num + already_travel > (total_num + 1) / 2)
	{
		return get_mid_num(p->left);
	}
	else
	{
		already_travel += p->left_child_num;
		return get_mid_num(p->right);
	}



}
*/
int target(0);

int get_num_pos(int pos, int& al, Node* p)
{
	if (p == NULL)
		return 0;
	
	get_num_pos(pos, al, p->left);
	al++;
	if (pos == al)
	{
		target = p->val;
		return 0;
	}
	get_num_pos(pos, al, p->right);
	return 0;
}

int module2()
{
	int number;
	cin >> number;
	Node* head=NULL;

	for (int i(0); i < number; i++)
	{
		int mydata;
		cin >> mydata;
		total_num++;
		if (head == NULL)
		{
			Node* temp = new Node;
			temp->val = mydata;
			head = temp;
			test_simpler_test(head);
			cout << endl;
			cout << "result  " << mydata << endl;
		}
		else
		{
			//build(mydata, head);
			build2(mydata, head);//first test build tree module
			//cout << "result  " << get_mid_num(head) << endl;;
			if (total_num % 2 == 1)
			{
				int pos = 0;
				get_num_pos((total_num + 1) / 2, pos, head);
				test_simpler_test(head);
				cout << endl;
				cout << "resutlt: " << target << endl;
			}
			else
			{
				test_simpler_test(head);
				cout << endl;
				int pos = 0;
				get_num_pos((total_num) / 2, pos, head);
				int buf = target; 
				pos = 0;
				get_num_pos((total_num) / 2+1, pos, head);
				buf += target;
				cout << "resutlt: " << buf/2 << endl;
			}

		}
	}
	cout << endl;
	//test_visit(head);
	return 0;
}

int main()
{
	module2();
	return 0;
}
