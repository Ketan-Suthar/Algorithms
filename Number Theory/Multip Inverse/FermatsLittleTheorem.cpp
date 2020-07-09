#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli power(lli a, lli n, lli mod)
{
	lli res=1;
	while(n)
	{
		if(n%2)
		{
			res = ((res%mod) * (a%mod))%mod;
			n--;
		}
		else
		{
			a = ((a%mod) * (a%mod))%mod;
			n/=2;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	lli a,m,t;
	cin>>t;
	while(t--)
	{
		cin>>a>>m;
		cout<<"\na^-1 = "<<power(a,m-2,m);
	}
	return 0;
}