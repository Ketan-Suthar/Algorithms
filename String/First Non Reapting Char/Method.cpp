#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
	    int n;
	    string str;
	    cin>>n>>str;
	    pair<int,int> hash[26]={{0,0}};
	    pair<int,int> res = {-1, INT_MAX};
	    
	    for(int i=0;i<n;i++)
	    {
	        hash[str[i]-'a'].first += 1;
	        hash[str[i]-'a'].second = i;
	    }
	    for(auto p: hash)
	    {
	        if(p.first == 1 && (res.second > p.second))
	            res = p;
	    }
	    if(res.first==-1) cout<<res.first;
	    else cout<<str[res.second];
	    cout<<'\n';
	}
	return 0;
}