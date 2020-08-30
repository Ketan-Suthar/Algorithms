#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000000
bool primes[SIZE+1];

void fillPrimes(int n)
{
	for(int i=0; i<=SIZE; i++)
		primes[i] = 1;

	primes[0] = primes[1] = 0;

	for(int i=2; i*i <= n; i++)
		if(primes[i])
			for(int j=i*i; j<=n; j+=i)
				primes[j] = 0;
}

int main(int argc, char const *argv[])
{
	int q;
	cin >> q;
	fillPrimes(SIZE);
	while(q--)
	{
		int n;
		cin >> n;
		if(primes[n])
			cout << n << " is prime";
		else
			cout << n << " is NOT prime";
	}
	return 0;
}