#include <bits/stdc++.h>

using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define MOD 1000000007
#define lli long long int
#define ui unsigned int
#define REP(i, n) for(int i=1; i<=n; i++)


lli I[3][3], T[3][3], arr[3];

void mul(lli A[3][3], lli B[3][3], ui dim)
{
	lli res[dim+1][dim+1];
	REP(i, dim)
		REP(j, dim)
		{
			res[i][j] =0;
			REP(k,dim)
			{
				//res[i][j] += A[i][k] * B[k][j];
				lli x = (A[i][k] * B[k][j]) % MOD;
				res[i][j] = (res[i][j] + x) % MOD;
			}
		}
	
	REP(i, dim)
		REP(j, dim)
			A[i][j] = res[i][j];

	lli temp = (arr[1] * I[1][1] + arr[2] * I[2][1]) % MOD;
	return temp;
}

lli getFib(int n)
{
	if(n <= 2)	return arr[n];
	
	I[1][1] = I[2][2] = 0;
	I[1][2] = I[2][1] = 0;

	T[1][1] = 0;
	T[1][2] = T[2][1] = T[2][2] = 1;	
	n--;

	while(n)
	{
		if(n%2)
			mul(I, T, 2), n--;
		else
			mul(T, T, 2), n /= 2;
	}
}

int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>arr[1]>>arr[2]>>n;
		cout<<getFib(++n)<<endl;
	}
	return 0;
}