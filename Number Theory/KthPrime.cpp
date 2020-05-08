#include <bits/stdc++.h>

using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define MAX 87000008

vector<int> primes;
bool isPrime[MAX+1];

void fillPrimes()
{
	isPrime[0] = isPrime[1] = 1;
	
	for(int i=2; i*i <=MAX; i++)
		if(!isPrime[i])
			for(int j = i*i; j<=MAX; j+=i)
				isPrime[j] = 1;
				
	for(int i=2; i<=MAX; i++)
		if(!isPrime[i])
			primes.push_back(i);
}

int main()
{
	// your code goes here
	FAST;
	fillPrimes();
	int q, n;
	cin >> q;
	while(q--)
		cin >> n, cout << primes[n-1] << "\n";
	return 0;
}