#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,sum,p;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>p;
		int total = 1<<n;
		bool flag=0;
		for(int mask=0;mask<total;++mask)
		{
			sum=0;
			for(int i=0;i<n;i++)
			{
				int f= 1<<i;
				if(!(mask&f))
					sum += arr[i];
			}
			if(sum == p)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}