class Solution {
public:
    int fun(vector<int>& arr, int n, int amount)
    {
        int dp[n+1][amount+1];
        for(int i=0; i<=amount;i++) dp[0][i] = INT_MAX-1;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0; i<=amount;i++)
        {
            if(i%arr[0]==0) dp[1][i] = (i/arr[0]);
            else INT_MAX-1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=amount;j++)
            {
                if(arr[i-1] > j) dp[i][j]= dp[i-1][j];
                else
                    dp[i][j] = min(1+dp[i][j-arr[i-1]], dp[i-1][j]);
            }
        if(dp[n][amount] == INT_MAX-1)
            return -1;
        return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        return fun(coins, n, amount);
    }
};