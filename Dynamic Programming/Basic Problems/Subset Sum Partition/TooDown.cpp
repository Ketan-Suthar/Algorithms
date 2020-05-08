#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

bool fun(int arr[], int n)
{
    unsigned int sum = 0;
    for(int i = 0; i < n; i++)
        sum +=arr[i];
    //cout << n << " " << sum;
    if(sum & 1)
        return 0;
    sum /= 2;
    bool subset[n+1][sum+1]; 

    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 

    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 

     for (int i = 1; i <= n; i++) 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<arr[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         else
           subset[i][j] = subset[i-1][j] || subset[i - 1][j-arr[i-1]]; 
       }
     return subset[n][sum]; 
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, arr[SIZE+1];
	    cin >> n;
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	        
	    if(fun(arr, n))
	        cout <<  "YES";
	    else
	        cout << "NO";
	    cout <<  "\n";
	}
	return 0;
}