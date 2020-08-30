#include <bits/stdc++.h>

using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define REP(i,n) for (int i = 1; i <= n; ++i)
#define MOD 10000000007
#define MAX 100005
#define lli long long int
#define ll long long
#define endl "\n"

int pre[MAX], suff[MAX], arr[MAX];

int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	int q, t, n, l, r;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		REP(i,n) cin>>arr[i];

		pre[0] = suff[n+1] = 0;
		
		REP(i, n) pre[i] = gcd(arr[i], pre[i-1]);
		for(int i=n; i>=1; i--)
			suff[i] = gcd(arr[i], suff[i+1]);

		while(q--)
		{
			cin>>l>>r;
			cout<<gcd(pre[l-1], suff[r+1])<<endl;
		}

	}
	return 0;
}