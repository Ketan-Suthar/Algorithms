class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        int edit[n+1][m+1];
        edit[0][0]=0;
        for(int i=1; i<=n; i++)
            edit[i][0] = edit[i-1][0]+1;
        for(int i=1; i<=m; i++)
            edit[0][i] = edit[0][i-1]+1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(word1[i-1] == word2[j-1])
                    edit[i][j] = edit[i-1][j-1];
                else
                    edit[i][j] = 1 + min(edit[i-1][j-1],
                                min(edit[i-1][j], edit[i][j-1]));
            }
        }
        return edit[n][m];
    }
};