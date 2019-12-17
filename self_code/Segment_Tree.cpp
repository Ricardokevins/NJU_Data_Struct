#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int l,r,sum,lazy;
	node(){l=r=sum=lazy=0;}
}a[N];

inline void update(int k)
{
	a[k].sum=a[k*2].sum+a[k*2+1].sum;
}

void build(int k/*当前节点的编号*/,int l/*当前区间的左边界*/,int r/*当前区间的右边界*/)
{
	a[k].l=l,a[k].r=r;

	if(l==r)//递归到叶节点
	{
		a[k].sum=number[l];//其中number数组为给定的初值
		return;
	}
	int mid=(l+r)/2;//计算左右子节点的边界
	build(k*2,l,mid);//递归到左儿子
	build(k*2+1,mid+1,r);//递归到右儿子
	update(k);//记得要用左右子区间的值更新该区间的值
}

void change(int k/*当前节点的编号*/,int x/*要修改节点的编号*/,int y/*要把编号为x的数字修改成y*/)
{
	if(a[k].l==a[k].r)
    {
        a[k].sum=y;
        return;
    }
	//如果当前区间只包含一个元素，那么该元素一定就是我们要修改的。
	//由于该区间的sum一定等于编号为x的数字，所以直接修改sum就可以了。
	int mid=(a[k].l+a[k].r)/2;//计算下一层子区间的左右边界
	if(x<=mid) change(k*2,x,y);//递归到左儿子
	else change(k*2+1,x,y);//递归到右儿子
	update(k);
}

void changeSegment(int k,int l,int r,int x)
//当前到了编号为k的节点，要把[l..r]区间中的所有元素的值+x
{
	if(a[k].l==l&&a[k].r==r)//如果找到了全部元素都要被修改的区间
	{
		a[k].sum+=(r-l+1)*x;
		//更新该区间的sum
		a[k].lazy+=x;return;
		//懒惰标记叠加
	}
	int mid=(a[k].l+a[k].r)/2;
	if(r<=mid) changeSegment(k*2,l,r,x);
	//如果被修改区间完全在左区间
	else if(l>mid) changeSegment(k*2+1,l,r,x);
	//如果被修改区间完全在右区间
	else changeSegment(k*2,l,mid,x),changeSegment(k*2+1,mid+1,r,x);
	//如果都不在，就要把修改区间分解成两块，分别往左右区间递归
	update(k);
	//记得更新点k的值
}
