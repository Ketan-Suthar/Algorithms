#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

static int table[SIZE+1][SIZE+1];

// this will take more than 1.5 secs for string size max 1000

bool isPalindrome(string str, int i, int j)
{
    while(i <= j)
    {
        if(str[i] != str[j])
            return 0;
        ++i;
        --j;
    }
    return 1;
}

int fun(string str, int i, int j)
{
    if(i >= j)
        return 0;
    if(table[i][j] != -1)
        return table[i][j];
    if(isPalindrome(str, i, j))
        return 0;
    
    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int left, right;
        if(table[i][k] == -1)
            left = table[i][k] = fun(str, i, k);
        else
            left = table[i][k];
        if(table[k+1][j] == -1)
            right = table[k+1][j] = fun(str, k+1, j);
        else
            right = table[i][j];
        int temp =  left + right + 1;
        if(ans > temp)
            ans = temp;
    }
    return table[i][j] = ans;
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    memset(table, -1, sizeof table);
	    cout << fun(str,0, str.size()-1);
	    cout<<"\n";
	}
	return 0;
}