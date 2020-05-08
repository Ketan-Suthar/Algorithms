#include<bits/stdc++.h> 
using namespace std;
#define MAX 500 


int main(int argc, char const *argv[])
{
	int arr[MAX];
	int n, result=0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < 31; ++i)
	{
		int cntZ = 0, cntO = 0;
		for(int j=0; j < n; ++j)
		{
			if(arr[j] & (1 << i))
				++cntO;
			else
				++cntZ;
		}
		int p = cntZ * cntO;
		result += (1 << i) * p;
	}
	cout << "\n" << result;

	return 0;
}