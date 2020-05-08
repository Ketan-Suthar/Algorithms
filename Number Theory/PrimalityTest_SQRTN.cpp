#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
	if(n == 1)
		return false;
	for (int i = 2; i*i <= n; ++i)
		if(n % i == 0)
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	if(isPrime(n))
		cout << n << " is prime";
	else
		cout << n << " is NOT prime";
	return 0;
}