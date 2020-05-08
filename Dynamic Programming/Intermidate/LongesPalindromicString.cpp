#include <bits/stdc++.h>
using namespace std;

#define SIZE 1001

static int table[SIZE+1][SIZE+1];
// int max(int a, int b)  
// {  
//     return (a > b)? a : b;  
// }

int fun(string text1, int m, string text2, int n)
{
    int i, j;  

    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            table[i][j] = 0;  

        else if (text1[i - 1] == text2[j - 1])  
            table[i][j] = table[i - 1][j - 1] + 1;  

        else
            table[i][j] = max(table[i - 1][j], table[i][j - 1]);  
        }  
    } 
    // for (i = 0; i <= m; i++)  
    // {  
    //     for (j = 0; j <= n; j++)  
    //         cout << table[i][j] << " ";
    //     cout << "\n";
    // }
    return table[m][n];
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string str1;
	    cin >> str1;
	    memset(table, -1, sizeof table);
	    int s1 = str1.size();
        string str2 = str1;
        reverse(str2.begin(), str2.end());
	    int ans = fun(str1, s1, str2, s1);

	    cout << ans << "\n";
	}
	return 0;
}