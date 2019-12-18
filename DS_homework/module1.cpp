#include<iostream>
using namespace std;
#define max_size 10000

int my_data[max_size]={0};
int pre_sum[max_size]={0};
int after_data[max_size]={0};
int has_num[max_size]={0};
int has_num_sum[max_size]={0};

int data_size,ask_size;

/*
*合并两个数组（按升序排列）
*输入：
*	a 数组首地址
*   需要合并的第一个数组是a[p...q]
*   需要合并的第二个数组是a[q+1...r]]
*/
void merge(int *a, int p, int q, int r) {
	int *tmp = new int[r - p + 1];
	if (tmp==NULL) return;
 
	int k = 0, i = p, j = q+1;
	while (i <= q && j <= r) {
		if (a[i] <= a[j]) {
			tmp[k++] = a[i++];
		}
		else {
			tmp[k++] = a[j++];
		}
	}
 
 
	if (i <= q ) {
		while (i <= q) {
			tmp[k++] = a[i++];
		}
	}
	else {
		while (j <= r) {
			tmp[k++] = a[j++];
		}
	}
	//memcpy(a + p, tmp, (r - p + 1) * sizeof(int));//注意这里是a+p，因为需要存放的数组首地址是a+p
	for (int c = 0; c < r - p + 1; c++) {
		a[p + c] = tmp[c];
	}
	
	delete[] tmp;
}
 
/*
*归并排序迭代
*输入：
*	a 数组首地址
*   p 排序区间起始序号
*   q 排序区间停止序号
*/
void merge_sort_c(int *a, int p, int r) {
	if (p >= r) return;
 
	int q = (p + r) / 2;
	
	merge_sort_c(a, p, q);
	merge_sort_c(a, q + 1, r);
	merge(a, p, q, r);
}
 
/*
*归并排序
*输入：
*	a 数组首地址
*   n 数组元素个数
*/
void mergeSort(int *a, int n) {
	if (n <= 1)
		return;
	
	merge_sort_c(a, 0, n - 1);
}

int unique_data()
{
	int pos(0);
	int count(1);
	int cur_target=my_data[0];
	for(int i(1);i<data_size;i++)
	{
		if(my_data[i]==cur_target)
			count++;
		else
		{
			has_num[pos]=count;
			after_data[pos]=cur_target;
			count=1;
			cur_target=my_data[i];
			pos++;
		}
	}
	has_num[pos]=count;
	after_data[pos]=cur_target;
	data_size=pos+1;//here update the data_size Attention!!!!!
	return 1;
}


int binarySearch1(int a[], int n , int target)//循环实现
{
	int low = 0 ,high = n , middle;
	while(low < high)
	{
	   middle = (low + high)/2;
       if(target == a[middle])
		   return middle;
	   else if(target > a[middle])
		   low = middle +1;
	   else if(target < a[middle])
		   high = middle;
	}
	return middle;
};



int module1()
{
    
    cin>>data_size>>ask_size;
    for(int i(0);i<data_size;i++)
    {
        cin>>my_data[i];
    }
	
    mergeSort(my_data, data_size);//sort test pass 
    for(int i(0);i<data_size;i++)
    {
    	cout<<my_data[i]<<" ";
	}
	cout<<endl;
	unique_data();//unique data test pass
	
    pre_sum[0]=after_data[0]*has_num[0];
    for(int i(1);i<data_size;i++)
    {
        pre_sum[i]=pre_sum[i-1]+after_data[i]*has_num[i];
    }
	has_num_sum[0]=has_num[0];
	for(int i(1);i<data_size;i++)
	{
		has_num_sum[i]=has_num_sum[i-1]+has_num[i];
	}
    for(int i(0);i<ask_size;i++)
    {
        int l,r;
        cin>>l>>r;
		int left_pos;
		int right_pos;
		left_pos=binarySearch1(after_data,data_size,l);
		right_pos=binarySearch1(after_data,data_size,r);

		if(after_data[left_pos]<l)
		{
			left_pos++;
		}
		if(after_data[right_pos]>r)
		{
			right_pos--;
		}
		int ask_result(0);
		if(right_pos<0&&left_pos>=data_size&&left_pos>right_pos)
		{
			cout<<ask_result<<endl;
			continue;
		}

		int data_number=has_num_sum[right_pos]-has_num_sum[left_pos]+has_num[left_pos];
		int sum_total=pre_sum[right_pos]-pre_sum[left_pos]+after_data[left_pos]*has_num[left_pos];
		ask_result=sum_total/data_number;
		cout<<ask_result<<endl;
		
		


    }
	

}

int main()
{
	//test
	module1();
	return 0;
}


