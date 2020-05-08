#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

static int table[SIZE+1][SIZE+1];

int fun(int arr[], int i, int j)
{
    if(i == j)
        return 0;
    if(table[i][j] != -1)
        return table[i][j];
    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp = fun(arr, i, k) + fun(arr, k+1, j);
        temp += (arr[i-1]*arr[k]*arr[j]);
        if(temp < ans)
            ans = temp;
    }
    //cout << ans << " ";
    return table[i][j] = ans;
}

int main() 
{
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int arr[SIZE];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	   memset(table, -1, sizeof table);
	   cout << fun(arr, 1, n-1) << "\n";
	}
	return 0;
}