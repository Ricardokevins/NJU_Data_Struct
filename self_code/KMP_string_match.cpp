#include<iostream>
#include<vector>
using namespace std;
vector<int> get_next(string a)
{
    vector<int>next;
    next.push_back(-1);
    int j=-1;
    for(int i(0);i<a.size();)
    {
        if(j==-1||a[i]==a[j])
        {
            i++;
            j++;
            next.push_back(j);
        }
        else
        {
            j=next[j];          
        }   
    }
    next.pop_back();
    return next;
}

bool KMP_find(string a,string b)
{
	vector<int>next=get_next(b);
	int pos=0;
	for(int i(0);i<a.size();)
	{
	
		if(pos>=int (next.size()))
		{
			cout<<"I find it"<<endl;
			return true;
		}
		if(pos==-1||b[pos]==a[i])
		{
			pos++;
			i++;
		}
		else
		{
			pos=next[pos];
		}

	}
	cout<<"no match result"<<endl;
	return false;
}

int find_it(string a,string b)
{
	for(int i(0);i<a.size();i++)
	{
		int j(0);
		for(;j<b.size();j++)
		{
			if(i+j>=a.size())
			{
				break;
			}
			if(a[i+j]!=b[j])
			{
				break;
			}		
		}
		if(j==b.size())
		{
			cout<<"I find it"<<endl;
			return 0;
		}
	}
	cout<<"no match result"<<endl;
	return 0;
}
int main()
{
    string a="ababashdlahdljshldkahldjslkdjjldkjflKJDLKFjlksdjflkzjdlkfjdlkjflkjlkjflkzdjlkfjlksjdlaksjalksjdkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkaaaaaaaaaaaaaaaaaaaaaaiiiiiiiiiiiiiiiiiiippppppppppppppppnalndlasndlansdlkajsldkjsaldkjalskdjalskjdalkjlknsldkfalwjeklwjlkadnlknsldkalskdjadghlkjdflkjsdlkfjlkdjflkjdflkjsdfiweivvvvvvdfasfafafaalkdjalkheelohello rldsdhaldjlakjdlkajdlkrldvworldvv";
    string b="world";
   	KMP_find(a,b);
   	find_it(a, b);
    return 0;

}
