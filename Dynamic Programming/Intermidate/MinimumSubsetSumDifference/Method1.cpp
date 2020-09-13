#define N 200
#define M 20000

bool dp[N][M];

void helper(vector<int> &A, int sum, bool dp[][M])
{
    for(int i=1; i<=A.size(); i++)
        for(int j=1; j<=sum; j++)
        {
            if(A[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - A[i-1]];
        }
}

int Solution::solve(vector<int> &A)
{
    int size = A.size(), sum=0;
    if(size==0)
        return 0;
    for(int x: A)
        sum += x;
    memset(dp, false, sizeof(dp));
    for(int i=0; i<=sum; i++) dp[0][i] = false;
    for(int i=0; i<=size; i++) dp[i][0] = true;
    
    helper(A, sum, dp);
    int i;
   
    for(i=sum/2; i>=0; i--)
        if(dp[size][i])
            break;
    return sum-(2*i);
}
