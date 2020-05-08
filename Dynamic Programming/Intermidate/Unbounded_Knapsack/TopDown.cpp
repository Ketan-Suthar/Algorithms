#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

long int fun(int values[], int weights[], int n, int cap)
{
    int topdown[SIZE+1][SIZE+1] = {{0}};

    for (int i = 1; i < n+1; ++i)
    	for (int j = 1; j < cap+1; ++j)
    	{
    		if(weights[i-1] > j)
    			topdown[i][j] = topdown[i-1][j];
    		else
    			topdown[i][j] = max(values[i-1] + topdown[i][j - weights[i-1]], 
    				topdown[i-1][j]);
    	}
    
    return topdown[n][cap];
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, capacity;
	    cin >> n >> capacity;
	    int values[SIZE+1], weights[SIZE+1];
	    
	    for(int i=0; i<n; i++)
	        cin >> values[i];
	    for(int i=0; i<n; i++)
	        cin >> weights[i];
	    cout << fun(values, weights, n, capacity) << "\n";
	}
	return 0;
}