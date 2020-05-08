#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

static int table[SIZE+1][SIZE+1];

int fun(char text1[], int m, char text2[], int n)
{
    int i, j, max = 0;
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
            if (i == 0 || j == 0)  
                table[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])  
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                if(table[i][j] > max)
                    max = table[i][j];
            } 
    
            else
                table[i][j] = 0;
        }  
    }  
    return max; 
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int size1, size2;
	    cin >> size1 >> size2;
	    char str1[size1], str2[size2];
	    cin >> str1 >> str2;
	    memset(table, 0, sizeof table);
	    
	    cout << fun(str1, size1, str2, size2) << "\n";
	   // for(int i=0; i<= size1; i++)
	   // {
	   //     for(int j=0; j<=size2; j++)
	   //         cout << table[i][j] << " ";
	   //     cout<<'\n';
	   // }
	}
	return 0;
}