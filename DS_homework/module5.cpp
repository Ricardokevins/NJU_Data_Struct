#include<iostream>
using namespace std;
//pass OJ test
int main()
{
    int num;
    cin>>num;
    int my_max;
    int my_min;
    int test_data[num];

    //读入测试数据
    for(int i(0);i<num;i++)
    {
        cin>>test_data[i];
    }
    //初始化最大和最小就是当前的第一个数据，然后开始循环找最大和最小了
    my_max=test_data[0];
    my_min=test_data[0];
    for(int i(1);i<num;i++)
    {
        if(test_data[i]>my_max)
        {
            my_max=test_data[i];
        }
        if(test_data[i]<my_min)
        {
            my_min=test_data[i];
        }
    }
    int bar,pos;
    //根据刚才找到的最大和最小来计算每一个桶的区间大小
    double temp_bar=double((my_max-my_min)*1.0/(num-1));
    if(temp_bar>1)
    {
        bar=temp_bar+1;
    }
    else
    {
        bar=temp_bar;
    }
    //设置一个最大桶和最小桶
    //具体的思路可以看看实验报告
    //但是在这里就简单的再说明一下
    //由于求的是最大的断档，然后这个桶实际上保存的是一段区间，对于最大的这种问题
    //只要保存一下区间的两个端点就行，然后上一段区间的最大和下一段区间的最小就是一个断档
    int bucket[num];
    int bucket1[num];
    
    for(int i(0);i<num;i++)
    {
        bucket[i]=0;
        bucket1[i]=0;
       
    }
    for(int i(0);i<num;i++)
    {
        pos=(test_data[i]-my_min)/bar;//对读入的数据进行处理，放到区间桶里，放到区间桶的本质就是看看会不会成为断点，不能的话就没有保存的意义了
        if(bucket[pos]==0)
        {//如果桶还是空的，那么就顺理成章的直接成了端点值
            bucket[pos]=bucket1[pos]=test_data[i];
        }
        else{
            if(test_data[i]<bucket[pos])
            {//不然的话就看看有没有资格成为端点而呗保留
                bucket[pos]=test_data[i];
            }
            if(test_data[i]>bucket1[pos])
            {
                bucket1[pos]=test_data[i];
            }
        }
    }
    int dif,max_dif=0;
    int temp=0;
    //遍历一次桶，然后求断档，求法上面刚刚说过
    for(int i(1);i<num;i++)
    {
        if(bucket[i]==0)
        {
            temp++;
        }
        else{
            dif=bucket[i]-bucket1[i-1-temp];
            if(max_dif<dif)
            {
                max_dif=dif;
            }
            temp=0;
        }
    }
    cout<<max_dif<<endl;
    return 0;
}