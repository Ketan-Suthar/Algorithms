#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n], dp[m+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    for(int i=0;i<n;i++)
    {
        int curr = arr[i];
        for(int j=m; j>=curr; j--)
        {
            if(dp[j] || !dp[j-curr])
                continue;
            dp[j] = 1;
        }
    }
    cout<<dp[m];
    return 0;
}
