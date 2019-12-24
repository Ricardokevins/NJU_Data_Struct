#include<iostream>
#include<string>
using namespace std;
 //pass OJ test
#define my_size 10000
struct Node {
    bool use = false;
    string data = "";
    Node* next = NULL;
};
 
 
 
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
    rel_pos = rel_pos % 1000;
    return rel_pos;
}
 
int part4()
{
    Node my_data[my_size];
    int num1;
    cin >> num1 ;
    for (int i(0); i < my_size; i++)
    {
        my_data[i].use = false;
        my_data[i].data = "";
        my_data[i].next = NULL;
    }
 
     
    for (int i(0); i < num1; i++)
    {
        string temp;
        cin >> temp;
         
        int pos = hash_map(temp);
        //cout << pos << endl;
        if (!my_data[pos].use)
        {
            my_data[pos].data = temp;
            my_data[pos].use = true;
        }
        else
        {
             
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
 
        string temp2;
        cin >> temp2;
        int pos2 = hash_map(temp2);
        //cout << pos << endl;
        if (!my_data[pos2].use )
            cout << "false" << endl;
        else
        {
            Node* cur = &my_data[pos2];
            while (cur!=NULL&&cur->next != NULL && cur->data != temp2)
            {
                cur = cur->next;
            }
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
