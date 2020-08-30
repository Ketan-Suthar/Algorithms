#include <bit/stdc++.h>

using namespace std;

int coinChange(std::vector<int> &coins, int amount)
{
	int coinsSize = coins.size();
	int dp[amount+1];
	int INF = 10000000;
	for(int i=0; i<=amount; i++)
		dp[i]=INF;

	for (int i = 1; i <= amount; ++i)
	{
		int ans = INF;
		for (int j = 0; j < conisSize; ++j)
		{
			ans =  min(ans, dp[i - coins[j]]);
		}
		if(ans == INF)
			dp[i]=INF;
		else
			dp[i]=ans+1;
	}
	return dp[amount];
}