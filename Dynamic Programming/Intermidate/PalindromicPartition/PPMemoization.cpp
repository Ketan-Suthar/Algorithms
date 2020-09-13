int table[10001][10001];
// User function Template for C++
bool isPalindrome(string s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])
            return 0;
        ++i, --j;
    }
    return 1;
}
int helper(string s, int i, int j)
{
    if(i >= j)
        return 0;
    if(table[i][j] != -1)
        return table[i][j];
    if(isPalindrome(s, i, j))
        return 0;
    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int left, right;
        if(table[i][k] == -1)
            left = table[i][k] = helper(s, i, k);
        else
            left = table[i][k];
        if(table[k+1][j] == -1)
            right = table[k+1][j] = helper(s, k+1, j);
        else
            right = table[k+1][j];
        if((left+right+1) < ans)
            ans = (left+right+1);
    }
    return table[i][j] = ans;
}


class Solution{
private:
    
public:
    
    int palindromicPartition(string str)
    {
        // code here
        memset(table, -1, sizeof(table));
        return helper(str, 0, str.size()-1);
    }
};