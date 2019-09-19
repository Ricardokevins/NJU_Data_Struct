/*
题目描述
小蓝鲸在构思作⽂时⽂思如泉涌，但是她怕写着写着⼿酸，于是她决定只写压缩后的版本。怎么压缩呢？她决定把重复的⼀段⽂字压缩成重复次数[最小重复单元] 的形式。例如， agkdgkd 会被压缩成 a2[gkd] 。但是⽼师在批阅的时候看不懂压缩后的作⽂，于是向你（小蓝鲸的好友）求助，希望你能帮她把小蓝鲸的作⽂还原。
注意，小蓝鲸未压缩的作⽂都是⽤小写的英⽂字⺟写的。
请不要使⽤递归⽅法来解题。
输入
⼀⾏字符串，压缩后的小蓝鲸的作⽂，只含有数字、小写字⺟、[ 和 ] 4种符号。（0≤小蓝鲸压缩后的作⽂⻓度≤200）
输出
⼀⾏字符串，小蓝鲸原始的作⽂。
样例输入
a3[d2[t]o]j
样例输出
adttodttodttoj
*/
#include<iostream>
using namespace std;

class MyStack {
public:
	char A[200000];
	int top;
	bool mPush(char a);
	bool mpop(char& a);
	MyStack();
};

int copy_stack(MyStack& s1, MyStack& s2, int n)
{
	char a[200000] = {0};
	int i(0);
	for (; i < 200000 && s2.top >= 0; i++)
	{
		s2.mpop(a[i]);
	}
	
	while (n > 0)
	{
		for (int j(0); j < i; j++)
		{
			s1.mPush(a[j]);
		}
		n--;
	}
	return 1;

}

bool MyStack::mPush(char a)
{
	top++;
	A[top] = a;
	return true;
}

bool MyStack::mpop(char& a)
{
	if (top >= 0)
	{
		a = A[top];
		top--;
		return true;
	}
	else
		return false;
}

bool isDigit(char c) {
	return '0' <= c && c <= '9';
}

int char_to_num(char a)
{
	return a - '0';
}

MyStack::MyStack()
{
	for (int i(0); i < 200000; i++)
	{
		A[i] = '\0';
	}
	top = -1;
}

int main()
{
	MyStack s1;
	MyStack s2;
	
	char A[200]={0};
	while (cin.getline(A, 200))
		//cin.getline(A,200);
	{
		int num_flag(3);
		for (int j(199); j >= 0;)
		{
			if (A[j] != '\0')
			{
				if (A[j] == ']')
				{
					s1.mPush(A[j]);
					j--;
					continue;
				}
				if (A[j] >= 'a' && A[j] <= 'z')
				{
					s1.mPush(A[j]);
					j--;
					continue;
				}
				if (isDigit(A[j]))
				{
					int res(0);
					int numflag(1);
					while (j >= 0 && isDigit(A[j]))
					{				
						res += char_to_num(A[j])*numflag;
						numflag = numflag * 10;
						j--;
					}
					//cout << res << endl;
					if (res == 3999)
					{
						//cout << "hhh stop" << endl;
					}
					//cout << s1.A << endl;
					//cout << s2.A << endl;
					copy_stack(s1, s2, res);
					continue;
				}
				if (A[j] == '[')
				{
					char temp_op;
					s1.mpop(temp_op);
					while (temp_op != ']')
					{
						s2.mPush(temp_op);
						s1.mpop(temp_op);
					}
					j--;
				}

			}
			else
				j--;
		}
		//cout << "dhaskdhskjdhsjkd" << endl;
		char coutp = '\0';
		/*
		while (s1.top >= 0)
		{
			s1.mpop(coutp);
			cout << coutp;
		}
		cout << endl;
		*/
		for (int k(200000 - 1); k >= 0; k--)
		{
			if (s1.A[k] != '\0')
			{
				cout << s1.A[k];
			}

		}
		cout << endl;

	}
	return 0;

}
