#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

static int table[SIZE+1][SIZE+1];


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
	    
	    cout << table[size1][size2] << "\n";
	}
	return 0;
}