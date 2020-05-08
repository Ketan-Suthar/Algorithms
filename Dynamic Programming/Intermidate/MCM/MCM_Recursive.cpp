#include <bits/stdc++.h>
using namespace std;

int fun(int arr[], int i, int j)
{
    if(i == j)
        return 0;
    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp = fun(arr, i, k) + fun(arr, k+1, j);
        temp += (arr[i-1]*arr[k]*arr[j]);
        if(temp < ans)
            ans = temp;
    }
    //cout << ans << " ";
    return ans;
}

int main() 
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	   cout << fun(arr, 1, n-1) << "\n";
	}
	return 0;
}