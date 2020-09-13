#include <bits/stdc++.h>
using namespace std;

int main() 
{
	//code
	int n,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    int result;
	    int sums[n];
	    sums[0] = result = arr[0];
	    for(int i=1; i<n; i++)
	    {
	        sums[i] = max(sums[i-1]+arr[i], arr[i]);
	        if(sums[i]>result)
	            result = sums[i];
	    }
	    cout<<result<<'\n';
	}
	return 0;
}