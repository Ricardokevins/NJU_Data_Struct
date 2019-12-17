#include<iostream>
using namespace std;
#define max_size 10000
int my_data[max_size]={0};
int pre_sum[max_size]={0};
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
	if (tmp==nullptr) return;
 
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
	return -1;
};

int find_pos(int i,int left,int right)
{
    if(left==right)
    {
        return left;
    }
    else{
        int mid=(left+right)/2;
        if(mid==left)
        {

        }
    }
}

int module1()
{
    
    cin>>data_size>>ask_size;
    for(int i(0);i<data_size;i++)
    {
        cin>>my_data[i];
    }
    mergeSort(my_data, data_size);
    pre_sum[0]=my_data[0];
    for(int i(1);i<data_size;i++)
    {
        pre_sum[i]=pre_sum[i-1]+my_data[i];
    }

    for(int i(0);i<ask_size;i++)
    {
        int l,r;
        cin>>l>>r;

    }
}