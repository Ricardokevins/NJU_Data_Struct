#include<iostream>
using namespace std;
#define max_size 110100
 //pass OJ test
int my_data[max_size] = { 0 };
unsigned long long  pre_sum[max_size] = { 0 };
int  after_data[max_size] = { 0 };
int has_num[max_size] = { 0 };
int has_num_sum[max_size] = { 0 };
long long dir_sum = 0;
int data_size, ask_size;
int pre_size;

 
 
int unique_data() {
    int pos(0);
    int count(1);
    int cur_target = my_data[0];
    for (int i(1); i < data_size; i++) {
        if (my_data[i] == cur_target)
        {
            //printf("%d\n", cur_target);
            count++;
        }
        else {
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
 
    scanf("%d %d", &data_size, &ask_size);
    for (int i(0); i < data_size; i++) {
        scanf("%d", &my_data[i]);
        dir_sum += my_data[i];
    }
 
    //mergeSort(my_data, data_size);//sort test pass
    //insertionSort(my_data, data_size);
    shellSort(my_data, data_size);
 
     
    unique_data();//unique data test pass
    long long hh = 0;
    for (int i(0); i < data_size; i++)
    {
        hh += after_data[i];
    }
    int temp_count = 0;
    pre_sum[0] = 0;
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
 
 
    for (int i(0); i < ask_size; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int left_pos;
        int right_pos;
        left_pos = binarySearch1(after_data, data_size, l);
        right_pos = binarySearch1(after_data, data_size, r);
 
        while (after_data[left_pos] < l) {
            left_pos++;
        }
        while (after_data[right_pos] > r) {
            right_pos--;
        }
        left_pos = left_pos - 1;
 
         
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
 
 
