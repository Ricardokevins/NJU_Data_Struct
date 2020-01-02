#include<iostream>
using namespace std;
#define max_size 110100
 //pass OJ test
 //这里是先声明的一个数组用来存放输入的原始数据的
int my_data[max_size] = { 0 };
//前缀和的存储位置，由于数据很有可能会比较大，所以使用的是longlong
unsigned long long  pre_sum[max_size] = { 0 };
//这里放的是经过处理的，唯一化的数据
int  after_data[max_size] = { 0 };
//对应的这里是对应上面的唯一化的数据在原始数据中的个数
int has_num[max_size] = { 0 };
//这里存放了数据个数的前缀和
int has_num_sum[max_size] = { 0 };
long long dir_sum = 0;
int data_size, ask_size;
int pre_size;

 
 //这个函数就是用于把原来的数据进行唯一化，有多个重复数据化为一个并记录个数
int unique_data() {
    int pos(0);
    int count(1);
    int cur_target = my_data[0];
    for (int i(1); i < data_size; i++) {
        if (my_data[i] == cur_target)
        {
            //printf("%d\n", cur_target);
            //这里就是有相同的就个数加加
            count++;
        }
        else {
            //反之就是遇到不一样的了，就进行一系列的处理
            //更新数据，把原来的数据放到唯一化的数组，然后拿到新的这个不一样的数据作为比较的依据
            has_num[pos] = count;
            after_data[pos] = cur_target;
            count = 1;
            cur_target = my_data[i];
            pos++;
        }
    }
    has_num[pos] = count;
    after_data[pos] = cur_target;
    pre_size = data_size;
    data_size = pos + 1;//here update the data_size Attention!!!!!
 
    return 1;
}
 
 
int binarySearch1(int a[], int n, int target) {
    //利用二分法在唯一化的数组里查找对应数据的位置
    int low = 0, high = n, middle;
    while (low < high) {
        middle = (low + high) / 2;
        if (target == a[middle])
            return middle;
        else if (target > a[middle])
            low = middle + 1;
        else if (target < a[middle])
            high = middle;
    }
    return middle;
};
 

 
void shellSort(int array[],int n) {
    //希尔排序，没得说
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < n; i++) {
     
            int itermToInsert = array[i];
            int j = i - gap;
            while (j >= 0 && array[j] >= itermToInsert) {
                array[j + gap] = array[j];
                j -= gap;
            }
            array[j + gap] = itermToInsert;
        }
    }
}
 
int module1() {
 //读入数据
    scanf("%d %d", &data_size, &ask_size);
    for (int i(0); i < data_size; i++) {
        scanf("%d", &my_data[i]);
        dir_sum += my_data[i];
    }
 //对于数据进行排序
    
    shellSort(my_data, data_size);
 
     //唯一化数据
    unique_data();//unique data test pass

    int temp_count = 0;
    pre_sum[0] = 0;
    //初始化前缀和的第一个数据
    while (temp_count < has_num[0])
    {
        pre_sum[0] += after_data[0];
        temp_count++;
    }
    for (int i(1); i < data_size; i++) {
        unsigned long long temp=0;
        int count(0);
        while (count < has_num[i])
        {
            temp += after_data[i] ;
            count++;
        }
        pre_sum[i] = pre_sum[i - 1] + temp;
    }
    has_num_sum[0] = has_num[0];
    for (int i(1); i < data_size; i++) {
        has_num_sum[i] = has_num_sum[i - 1] + has_num[i];
    }
 //开始查询了，先是读入两个数据，然后使用二分计算位置
 
    for (int i(0); i < ask_size; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int left_pos;
        int right_pos;
        left_pos = binarySearch1(after_data, data_size, l);
        right_pos = binarySearch1(after_data, data_size, r);
 //对应的，可能找到数据的位置的一些偏差进行处理，因为区间可能不是刚好是数组的数据，利用二分可能有偏差
        while (after_data[left_pos] < l) {
            left_pos++;
        }
        while (after_data[right_pos] > r) {
            right_pos--;
        }
        left_pos = left_pos - 1;
 
     //这里对异常进行处理，可能是没找到，可能是越界，反正加强鲁棒性就对了    
        long long ask_result(0);
        if (right_pos<0 || left_pos >= data_size || left_pos>right_pos) {
            printf("%lld\n", ask_result);
            continue;
        }
         
        long long data_number;
        long long sum_total;
        if (left_pos == -1)
        {
            data_number = has_num_sum[right_pos];
            sum_total = pre_sum[right_pos];
        }
        else
        {
            data_number = has_num_sum[right_pos] - has_num_sum[left_pos];
            sum_total = pre_sum[right_pos] - pre_sum[left_pos];
        }
         //这里就没得说了，拿到了前缀和之后计算就完事了，这里注意前缀和数据里的数据是包括当前位置的数据的，所以在右减左的时候，左边的下标减一
         //可以看到前面的代码减了
        if (data_number == 0)
            printf("%lld\n", data_number);
        else {
            ask_result = sum_total / data_number;
           
                printf("%lld\n", ask_result);
            
        }
 
 
 
 
    }
    return 0;
 
}
 
int main() {
    //test
    module1();
    return 0;
}
 
 
