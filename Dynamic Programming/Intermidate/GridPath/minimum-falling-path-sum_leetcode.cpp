class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A)
    {
        int n = A.size(), m = A[0].size();
        int temp[n][m];
        for(int i=0; i<m; i++)
        {
             temp[n-1][i] = A[n-1][i];
        }
        for(int i=n-2; i>=0; i--)
            for(int j=0; j<m; j++)
            {
                temp[i][j] = A[i][j];
                int _min = temp[i+1][j];
                if((j-1) >= 0)
                    _min = min(temp[i+1][j-1], _min);
                if((j+1) < m)
                    _min = min(temp[i+1][j+1], _min);
                temp[i][j] += _min;
            }
        int res=INT_MAX;
        for(int i=0; i<m; i++)
            res = min(res, temp[0][i]);
        return res;
    }
};