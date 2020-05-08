#include <bits/stdc++.h>

using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define lli long long int
#define SIZE 1000001

int isPrime[SIZE];
int pp[SIZE];

void fillPrimes()
{
	for(lli i=0; i <= SIZE; i++)
		isPrime[i] = 1;
	isPrime[0] = isPrime[1] = 0;
	
	for(lli i=2; i*i <=SIZE; i++)
		if(isPrime[i])
			for(lli j = i*i; j<=SIZE; j+=i)
				isPrime[j] = 0;
				
	lli count=0;
	for(lli i=1; i <= SIZE; i++)
	{
		if(isPrime[i])
			++count;
		if(isPrime[count])
			pp[i] = 1;
		else
			pp[i] = 0;
	}
	for(lli i=1; i <= SIZE; i++)
		pp[i] += pp[i-1];
}

int main()
{
	// your code goes here
	FAST;
	fillPrimes();
	int q, l, r;
	cin >> q;
	while(q--)
	{
		cin >> l >> r;
		cout << pp[r] - pp[l-1]<< "\n";
	}
	return 0;
}