#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long
#define ui unsigned int
#define SIZE 50
int MOD = (1e9)+7;

ll arr[SIZE+1][SIZE+1], I[SIZE+1][SIZE+1];

void mul(ll A[][SIZE+1], ll B[][SIZE+1], ui m)
{
	ll res[SIZE+1][SIZE+1];
	REP(i, m)
		REP(j, m)
		{
			res[i][j] =0;
			REP(k,m)
				res[i][j] += A[i][k] * B[k][j];
		}
	
	REP(i, m)
		REP(j, m)
			A[i][j] = res[i][j];
}

void power(ui m, ui n)
{
	REP(i, m) 
		REP(j, m) 
		{
			if(i==j)
				I[i][j] = 1;
			else
				I[i][j] = 0;
		}
		
	while(n)
	{
		if(n%2)
			mul(I, arr, m), n--;
		else
			mul(arr, arr, m), n/=2;
	}
	REP(i, m) REP(j, m) arr[i][j] = I[i][j];
}
void printMatrix(ui m)
{
	REP(i, m)
	{
		REP(j, m)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
int main() 
{
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		ui m,n;
		cin>>m>>n;
		REP(i,m) REP(j,m) cin>>arr[i][j];
		
		power(m,n);
		printMatrix(m);
	}
	return 0;
}