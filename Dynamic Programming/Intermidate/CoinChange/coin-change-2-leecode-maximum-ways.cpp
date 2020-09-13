class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int size=coins.size(), dp[size+1][amount+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=size; i++) dp[i][0]=1;
        for(int i=1; i<=size; i++)
            for(int j=1; j<=amount; j++)
            {
                if(coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
            }
        return dp[size][amount];
    }
};