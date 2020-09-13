#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

static int table[SIZE+1][SIZE+1];
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}

int fun(string str1, int s1, string str2, int s2)
{
    if(s1 == 0 || s2 == 0)
        return 0;
    if(table[s1][s2] != -1)
        return table[s1][s2];
        
    if(str1[s1-1] == str2[s2-1])
        return table[s1][s2] = (1 + fun(str1, s1-1, str2, s2-1));
    return table[s1][s2] = max(fun(str1, s1, str2, s2-1), fun(str1, s1-1, str2, s2));
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string str1, str2;
	    cin >> str1 >> str2;
	    memset(table, -1, sizeof table);
	    int s1 = str1.size(), s2 = str2.size();
	    int ans = fun(str1, s1, str2, s2);
	    ans = s1 + s2 - ans;
	    cout << ans << "\n";
	}
	return 0;
}