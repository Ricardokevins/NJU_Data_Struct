#include<iostream>
#include<string>
using namespace std;
 //pass OJ test
#define my_size 10000

//创建我的开散列的数据结构
struct Node {
    bool use = false;
    string data = "";
    Node* next = NULL;
};
 
 
 //这里是我自己写的一个哈希函数，为了保证足够的随机
 //对数据进行了一定的处理，对于不同的字符使用ASCII码处理，同时乘上一个大质数，经过了一定的
 //测试（打印出哈希值）结果还是比较随机的。最后又模了一个大质数，然后在模大小
int hash_map(string a) {
    int sum(0);
    for (int i(0); i < 10; i++) {
        if (a[i] <= '9' && a[i] >= '5') {
            sum += (a[i] - '0') * 12281;
        }
        else {
            if (a[i] <= '4' && a[i] >= '0')
                sum += (a[i] - '0') * 218359;
            else
                sum += (a[i] - '0') * 3877817;
        }
    }
    int rel_pos = sum % 12331;
    rel_pos = rel_pos % 10000;
    return rel_pos;
}
 
int part4()
{
    Node my_data[my_size];
    int num1;
    cin >> num1 ;

    //初始化我的散列表
    for (int i(0); i < my_size; i++)
    {
        my_data[i].use = false;
        my_data[i].data = "";
        my_data[i].next = NULL;
    }
 
     //开始读入数据
    for (int i(0); i < num1; i++)
    {
        string temp;
        cin >> temp;
         
        int pos = hash_map(temp);
        //获得哈希值
        //cout << pos << endl;
        if (!my_data[pos].use)
        {
            my_data[pos].data = temp;
            my_data[pos].use = true;
            //没有用过，那就放进去，同时把使用的标记置为true
        }
        else
        {
             //用过那就往后加呗，在链表的尾部追加节点，没啥问题
            Node* cur = &my_data[pos];
            while (cur!=NULL&&cur->next != NULL)
            {
                cur = cur->next;
            }
            Node* hh = new Node;
            hh->data = temp;
            hh->next = NULL;
            if (cur == NULL)
                cur = hh;
            else
                cur->next = hh;
        }
    }
 //这里开始查询了
        string temp2;
        cin >> temp2;
        int pos2 = hash_map(temp2);
        //cout << pos << endl;
        if (!my_data[pos2].use )
            cout << "false" << endl;
        else
        {
            Node* cur = &my_data[pos2];
            //这里循环的条件有三个
            //当前不空，下一个不空，以及找到了
            while (cur!=NULL&&cur->next != NULL && cur->data != temp2)
            {
                cur = cur->next;
            }
            //退出循环之后自然是要仔细的看看是为啥退出的，是三个情况里的哪一种
            if(cur==NULL)
            {
                cout << "false" << endl;
                return 0;
            }
            if (cur->data == temp2)
            {
                cout << "true" << endl;
                return 0;
            }
            else
            {
                cout << "false" << endl;
                return 0;
            }
        }
     
    return 0;
}
 
int main()
{
    part4();
    return 0;
}
