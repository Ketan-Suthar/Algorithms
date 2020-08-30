#include <bits/stdc++.h>

using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int phi(int n)
{
	int res = n;
	for (int i = 2; i*i <= n; ++i)
	if(n % i == 0)
	{
		res /= i;
		res *= (i - 1);
		while(n % i == 0)
			n /= i;
	}
	if(n > 1)
		res /= n, res *= (n-1);
	return res;
}

int main(int argc, char const *argv[])
{
	FAST;
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<"\nphi("<<n<<"): "<<phi(n);
	}

	return 0;
}