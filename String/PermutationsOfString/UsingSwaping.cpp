#include <bits/stdc++.h>
using namespace std;

//#define swap(a, b) a^=b^=a^=b

void helper(int i, string str, int size)
{
    if(i == size-1)
        cout<<str<<' ';
    else
    {
        for(int  j=i; j<size; j++)
        {
            swap(str[i], str[j]);
            // to print in lexicographical order
            sort(str.begin()+j, str.end());
            helper(1+i, str, size);
            //cout<<str<<' ';
            swap(str[i], str[j]);
        }
    }
}

int main()
{
	//code
	int t;
	cin>>t;
	while(t--)
    {
        string str;
        cin>>str;
        helper(0, str, str.length());
        cout<<'\n';
    }
	return 0;
}