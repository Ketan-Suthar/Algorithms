#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

long int fun(int values[],int n, int cap)
{
    // int weights[n];
    // for(int i=0; i<n; i++)
    //     weights[i] = i+1;
        
    int topdown[SIZE+1][SIZE+1] = {{0}};

    for (int i = 1; i < n+1; ++i)
    	for (int j = 1; j < cap+1; ++j)
    	{
    		if(i > j)
    			topdown[i][j] = topdown[i-1][j];
    		else
    			topdown[i][j] = max(values[i-1] + topdown[i][j - i], 
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
	    int n;
	    cin >> n;
	    int values[SIZE+1], weights[SIZE+1];
	    
	    for(int i=0; i<n; i++)
	        cin >> values[i];
	    cout << fun(values, n, n) << "\n";
	}
	return 0;
}