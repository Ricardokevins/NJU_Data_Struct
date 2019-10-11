/*
题目描述
为了敦促自己在新的一学期认真学习，小蓝鲸决定记录自己每天的学习时长。在小蓝鲸看来，一天学习时间大于8小时的时候，就可以认为这是「劳累的一天」。而所谓「认真学习的时间段」，意味在这段时间内，小蓝鲸「劳累的天数」是严格大于「不劳累的天数」。  

为了更好地检点反省自己的学习状况，小蓝鲸希望你能帮他算出「认真学习的时间段」所持续的最长天数。  

下面以一个例子更好地说明，假设小蓝鲸记录了连续7天自己的学习时长，分别为[9,9,6,0,6,6,9]，可以得出最长的「认真学习的时间段」是[9,9,6]，长度为3天。 

输入
输入数据包括两行，第一行为一个整数n，满足1≤n≤100000，表示小蓝鲸记录自己学习时长的天数。第二行为n个非负整数，用空格隔开，第i个数ai表示小蓝鲸在第i天的学习时长，满足0≤ai≤16。

输出
输出数据仅一行，包含一个整数，表示最长的「认真学习的时间段」所持续的天数，行末无空格换行符。

样例输入
7
9 9 6 0 6 6 9
样例输出
3
提示
本题若使用O(n2)的算法，可能会导致超时，建议考虑O(nlogn)或O(n)时间复杂度的算法。
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int temp(0);
    vector<int>data;
    cin >> temp;
     
        for (int i(0); i < temp; i++)
        {
            int day(0);
            cin >> day;
            data.push_back(day);
        }
        int n = data.size();
        int res = 0;
        vector<int> sum(n + 1, 0);
 
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + (data[i] > 8 ? 1 : (-1));
            for (int j = 0; j <= i; ++j) {
                if (sum[i + 1] - sum[j] > 0) {
                    res = res> i + 1 - j?res: i + 1 - j;
                    break;
                }
            }
        }
        cout << res ;
     
    return 0;
 
}
/**************************************************************
    Problem: 1174
    User: 181860077
    Language: C++
    Result: 正确
    Time:620 ms
    Memory:1544 kb
****************************************************************/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int temp(0);
    vector<int>data;
    cin>>temp;
    for (int i(0); i < temp; i++)
    {
        int day(0);
        cin >> day;
        data.push_back(day);
    }
    int n=data.size();
    vector<int>pre_sum(n+1,0);
    for(int i(0);i<n;i++)
    {
        if(data[i]>8)
        {
            pre_sum[i+1]=pre_sum[i]+1;
        }
        else
        {
            pre_sum[i+1]=pre_sum[i]-1;
        }
    }
    vector<int>mystack;
    int length=0;
    for(int i(0);i<n+1;i++)
    {
        if(mystack.size()==0||pre_sum[mystack[mystack.size()-1]]>pre_sum[i])
        {
            mystack.push_back(i);
        }
    }
    int pos=n;
    while(pos>length)
    {
        while(mystack.size()!=0&&pre_sum[mystack[mystack.size()-1]]<pre_sum[pos])
        {
            length=length>(pos-mystack[mystack.size()-1])?length:pos-mystack[mystack.size()-1];
            mystack.pop_back();
        }
        pos--;
    }
    cout<<length;
    return length;
}
/**************************************************************
    Problem: 1174
    User: 181860077
    Language: C++
    Result: 正确
    Time:120 ms
    Memory:2452 kb
****************************************************************/
