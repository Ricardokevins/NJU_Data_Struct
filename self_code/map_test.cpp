#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    map<int,int>int2int;
    map<int,string>int2string;
    map<int,vector<int> >int2vec;

    //test insert
    int2int.insert(map<int,int>::value_type(2,3));
    int2int.insert(pair<int,int>(1,2));    
    int2int[3]=4;
	/* 
    //test visit
    map<int,int>::iterator iter=int2int.begin();
    for(;iter!=int2int.end();iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }

    //test find
    iter=int2int.find(3);
    if(iter==int2int.end())
        cout<<"not found"<<endl;
    else
        cout<<iter->second<<endl;
    
    //test delete
    iter=int2int.begin();
    iter=int2int.find(2);
    int2int.erase(iter);
    int2int.erase(1);
    iter=int2int.begin();
    iter=int2int.find(2);
    if(iter==int2int.end())
        cout<<"not find"<<endl;
    else
        cout<<iter->second<<endl;
   
    iter=int2int.begin();
    iter=int2int.find(1);
    if(iter==int2int.end())
        cout<<"not find"<<endl;
    else
        cout<<iter->second<<endl;
    return 0;
    
    map<int,int>::iterator iter=int2int.end();
    cout<<iter->first<<" "<<iter->second;
    iter=int2int.find(3);
    cout<<iter->first<<" "<<iter->second;
    */
    vector<int>test1;
    vector<int>test2;
    vector<int>test3;
    test1.push_back(6);
    test1.push_back(2);
    test2.push_back(7);
   // test2.push_back(4);
    test3.push_back(0);
    /*
    int2vec.insert(pair<int,vector<int> >(2,test1));
    int2vec.insert(pair<int,vector<int> >(1,test2));
    map<int,vector<int> >::iterator iter=int2vec.begin();
    cout<<iter->first<<endl;
    for(int i(0);i<iter->second.size();i++)
    {
    	cout<<iter->second[i]<<endl;
	}
    return 0;
	 */
	map<vector<int>,int> vec2int;
	vec2int.insert(pair<vector<int> ,int>(test2,1));
	vec2int.insert(pair<vector<int>,int>(test1,3));
	map<vector<int>,int>::iterator iter=vec2int.begin();
	for(int i(0);i<iter->first.size();i++)
	{
		cout<<iter->first[i]<<endl;
	}
	cout<<iter->second<<endl;
	cout<<endl;
	iter++;
	for(int i(0);i<iter->first.size();i++)
	{
		cout<<iter->first[i]<<endl;
	}
	cout<<iter->second<<endl;
	cout<<endl;
	return 0;
}
