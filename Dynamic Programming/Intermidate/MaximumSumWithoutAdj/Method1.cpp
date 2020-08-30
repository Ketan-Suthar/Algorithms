#include <bits/stdc++.h>
using namespace std;

int maxSumWithoutAdj(int *arr, int n)
{
    if(n==0)
        return -1;
    else if(n==1)
        return arr[n];
    int first = arr[0], second = max(arr[0], arr[1]);
    int curr=0;
    for(int i=2; i<n; i++)
    {
        curr = max(second, first + arr[i]);
        first = second;
        second = curr;
    }
    return second;
}

int main()
{
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout << maxSumWithoutAdj(arr, n)<<'\n';
	}
	return 0;
}