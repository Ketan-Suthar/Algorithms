#include <bits/stdc++.h>
using namespace std;

int noOfWays(int *coins, int n, int amount)
{
    int res[amount+1], coin;
    memset(res, 0, sizeof(res));
    res[0]=1;
    for(int i=0; i<n; i++)
    {
        coin = coins[i];
        for(int j=1; j<=amount; j++)
            if(coin <= j)
                res[j] += res[j-coin];
    }
    return res[amount];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, amount;
	    cin>>n;
	    int coins[n];
	    for(int i=0; i<n; i++)
	        cin>>coins[i];
	    cin>>amount;
	    cout << noOfWays(coins, n, amount)<<'\n';
	}
	return 0;
}