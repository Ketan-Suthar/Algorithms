#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

long int dpTable[SIZE+1][SIZE+1];

void print(int n, int w)
{
    cout <<"\ndpTable: \n";
    for(int i =0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
            cout << dpTable[i][j] << " ";
        cout << "\n";
    }
}

long int fun(int values[], int weights[], int n, int cap)
{
    if(n == 0 || cap == 0)
        return 0;
    if(dpTable[n][cap] != -1)
        return dpTable[n][cap];
    if(weights[n-1] <= cap)
        return dpTable[n][cap] = max(values[n-1] + fun(values, weights, n-1, cap - weights[n-1]),
                    fun(values, weights, n-1, cap));
    return dpTable[n][cap] = fun(values, weights, n-1, cap);
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
	    int values[n], weights[n];
	    memset(dpTable, -1, sizeof dpTable);
	    for(int i=0; i<n; i++)
	        cin >> values[i];
	    for(int i=0; i<n; i++)
	        cin >> weights[i];
	    cout << fun(values, weights, n, capacity) << "\n";
	    //print(n, capacity);
	}
	return 0;
}