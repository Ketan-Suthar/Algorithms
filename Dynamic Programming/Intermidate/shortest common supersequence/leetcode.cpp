class Solution {
public:
    int table[1000+1][1000+1];
    void helper(string str1, int size1, string str2, int size2)
    {
        memset(table, -1, sizeof table);
	    for(int  i=0; i<=size1; i++) table[0][i]=0;
	    for(int  i=0; i<=size2; i++) table[i][0]=0;
	    for(int i=1; i<=size1; i++)
	        for(int j=1;j<=size2;j++)
	        {
	            if(str1[i-1] == str2[j-1])
	                table[i][j] = 1 + table[i-1][j-1];
	            else
	                table[i][j] = max(table[i-1][j], table[i][j-1]);
	        }
    }
    string shortestCommonSupersequence(string str1, string str2)
    {
        string ans, result;
        if(str1 == str2)
            return str1;
        int size1 = str1.size(), size2 = str2.size();
        helper(str1, size1, str2, size2);
        int i = size1, j = size2;
        while(i && j)
        {
            if(str1[i-1] == str2[j-1])
            {
                result = result + str1[i-1];
                --i, --j;
            }
            else
                table[i-1][j] > table[i][j-1] ? --i : --j;
        }
        reverse(result.begin(), result.end());
        cout<<"LCS: "<<result;
        int s1=0, s2=0;
        i=0;
        while(s1 <= size1 && s2<=size2 && i < result.length())
        {
            if((str1[s1] == result[i]) && (str2[s2] == result[i]))
            {
                ans.push_back(result[i]);
                ++i, ++s1, ++s2;
            }
            else
                (str1[s1] == result[i]) ? ans += str2[s2++] : ans += str1[s1++];
        }  
        while(s1 < size1) ans.push_back(str1[s1++]);
        while(s2 < size2) ans.push_back(str2[s2++]);
        return ans;
    }
};