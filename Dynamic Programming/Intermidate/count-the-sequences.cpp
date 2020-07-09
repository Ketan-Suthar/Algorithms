#include<bits/stdc++.h>
using namespace std;

int MOD = (1e9)+7;
const int N = 1005;

int dp[N][N][3];

int main()
{

        int n,m;
        cin>>n>>m;
        if(n == 1)return cout<<m,0;
        for(int i=1;i<=m;i++)
        {
            dp[2][i][0] = i-1;
            dp[2][i][1] = 1;
            dp[2][i][2] = m-i;
        }
        for(int i=3;i<=n;i++)
        {
            int pre = 0;
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<3;k++)dp[i][j][1] += dp[i-1][j][k],dp[i][j][1]%=MOD;
                dp[i][j][0] += pre;dp[i][j][0]%=MOD;
                pre+=dp[i-1][j][1];pre%=MOD;
                pre+=dp[i-1][j][2];pre%=MOD;
            }
            pre = 0;
            for(int j=m;j>=1;j--)
            {
                dp[i][j][2] += pre;dp[i][j][2]%=MOD;
                pre+=dp[i-1][j][1];pre%=MOD;
                pre+=dp[i-1][j][0];pre%=MOD;
            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++)for(int j=0;j<3;j++)ans+=dp[n][i][j],ans%=MOD;
        cout<<ans<<endl;
    return 0;
}