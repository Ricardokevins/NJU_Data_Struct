#include<iostream>
using namespace std;
#define max_size 6000
int result[max_size] = { 0 };
int number, k;
 //pass OJ test

 //这里是我自己写的一个 atoi的函数，用了很多次了，基本没啥问题，支持处理负数
int change_num(string a)
{
    int num(0);
    int flag(0);
    if (a.size() == 0)
        return num;
    if (a[0] == '-')
    {
        flag = 1;
        a.erase(a.begin());
    }
    while (a.size() != 0)
    {
        num = num * 10;
        num += a[0] - '0';
        a.erase(a.begin());
    }
    if (flag)
        num = -num;
    return num;
}
 //打印结果，也没得说，由于初始化为0了，而且只要这个数组满了之后就不会有空，所以判断
 //有没有满（输出到哪里结束）用的就是不等于0
int print_result()
{
    //cout << "result: ";
    int i(k - 1);
    for (; i >= 0; i--)
    {
        if (result[i] != 0)
        {
            cout << result[i] << " ";
        }
        else
        {
            cout << endl;
            return 0;
        }
    }
    if(i<=0)
        cout << endl;
    return 0;
}

//写了一个新的函数进行插入数据，修复了各种的问题
 
int insert_data_fixed(int p)
{
    int pos(0);
    for (; pos < k; )
    {
        if (p < result[pos])
        {
            break;
        }
        pos++;
    }
    if (pos == 0)
    {
        result[0] = p;  
    }
    else
    {
        if (pos == k)
        {
            for (int i(0); i < k - 1; i++)
            {
                result[i] = result[i + 1];
            }
            result[k - 1] = p;
        }
        else
        {
            for (int i(0); i < pos-1; i++)
            {
                result[i] = result[i + 1];
            }
            result[pos-1] = p;
             
        }
    }
    //cout << "Result: ";
    //for (int i(0); i < k; i++)
    //{
    //  cout << result[i] << " ";
    //}
    //cout << endl;
    return 0;
}
 
 
 
int module3()
{
    cin >> number >> k;
    //k--;
    int count = 0;
    while (count < number)
    {
        string a;
        cin >> a;
        if (a == "Check")
        {
            print_result();
        }
        else
        {
            int temp_data = change_num(a);
            //cout << "change result:" << temp_data << endl;
            if (temp_data > result[0])
            {
                //insert_data(change_num(a));
                insert_data_fixed(temp_data);
                //insert_data_very_fixed(temp_data);
            }
            count++;
        }
    }
    string a;
     //OJ特色：末尾多了一个check，那就再输出一次吧
    while (cin >> a)
    {
        print_result();
    }
    return 0;
}
 
int main()
{
    module3();
    return 0;
 
}