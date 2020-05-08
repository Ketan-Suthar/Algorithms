#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

int fun(int values[], int n, int sum)
{
    int topdown[n+1][sum+1];
    
    for(int i=0; i<=sum; i++)
        topdown[0][i] = 0;
    for(int i=0; i<=n; i++)
        topdown[i][0] = 1;

    for (int i = 1; i < n+1; ++i)
    	for (int j = 1; j < sum+1; ++j)
    	{
    		if(values[i-1] > j)
    			topdown[i][j] = topdown[i-1][j];
    		else
    			topdown[i][j] = (topdown[i][j - values[i-1]] + 
    				topdown[i-1][j]);
    	}
    // for (int i = 0; i < n+1; ++i)
    // {
    //     for (int j = 0; j < sum+1; ++j)
    //         cout << topdown[i][j] << " ";
    //     cout << "\n";
    // }
    return topdown[n][sum];
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, sum;
	    cin >> n;
	    int coins[n];
	    for(int i=0; i<n; i++)
	        cin >> coins[i];
	    cin >> sum;
	    
	    cout << fun(coins, n, sum) << "\n";
	}
	return 0;
}