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
    for(int i(0);i<num;i++)
    {
        cin>>test_data[i];
    }
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
    double temp_bar=double((my_max-my_min)*1.0/(num-1));
    if(temp_bar>1)
    {
        bar=temp_bar+1;
    }
    else
    {
        bar=temp_bar;
    }
    int bucket[num];
    int bucket1[num];
    
    for(int i(0);i<num;i++)
    {
        bucket[i]=0;
        bucket1[i]=0;
       
    }
    for(int i(0);i<num;i++)
    {
        pos=(test_data[i]-my_min)/bar;
        if(bucket[pos]==0)
        {
            bucket[pos]=bucket1[pos]=test_data[i];
        }
        else{
            if(test_data[i]<bucket[pos])
            {
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