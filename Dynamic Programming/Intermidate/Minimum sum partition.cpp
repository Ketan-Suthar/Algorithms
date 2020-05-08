#include <bits/stdc++.h>
using namespace std;
#define SIZE 50

int fun(int arr[], int n, int sum)
{
    bool topdown[n+1][sum+1]; 
    
    for (int i = 1; i <= sum; i++) 
      topdown[0][i] = 0; 
    for (int i = 0; i <= n; i++) 
      topdown[i][0] = 1; 

     for (int i = 1; i <= n; i++) 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<arr[i-1]) 
            topdown[i][j] = topdown[i-1][j]; 
         else
           topdown[i][j] = topdown[i-1][j] || topdown[i - 1][j-arr[i-1]]; 
       }
       int ans = INT_MAX;
        for (int i = 0; i <= (sum/2); i++)
            if(topdown[n][i])
                ans = min(ans, sum - (2 * i));
     return ans; 
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
	   
	    unsigned int sum = 0;
        for(int i = 0; i < n; i++)
            sum +=arr[i];
        
	    cout << fun(arr, n, sum);
	    cout <<  "\n";
	}
	return 0;
}