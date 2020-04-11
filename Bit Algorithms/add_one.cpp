#include <iostream> 
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int m = 1;
	while(m & n)
	{
		n ^= m;
		m <<= 1;
	}

	n ^= m;
	cout<< n;
	return 0;
}