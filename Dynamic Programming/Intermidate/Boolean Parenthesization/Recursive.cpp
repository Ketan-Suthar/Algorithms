#include <bits/stdc++.h>
using namespace std;

int fun(string str, int i, int j, bool isTrue)
{
    if(i > j)
        return 0;
    if(i == j)
    {
        
        if(isTrue)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }
    unsigned int ans = 0;
    for(int k=i; k < j; k++)
    {
        int lt = fun(str, i, k-1, 1);
        int rt = fun(str, k+1, j, 1);
        int lf = fun(str, i, k-1, 0);
        int rf = fun(str, k+1, j, 0);
        
        if(str[k] == '&')
        {
            if(isTrue)
                ans += (rt * rt);
            else
                ans += (lf * rf) + (lt * rf) + (lf * rt);
        }
        else if(str[k] == '|')
        {
            if(isTrue)
                ans += (lt * rt) + (lt * rf) + (lf * rt);
            else
                ans += (lf * rf);
        }
        else
        {
            if(isTrue)
                ans += (lt * rf) + (lf * rt);
            else
                ans += (lt * rt) + (lf * rf);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        cout << fun(str, 0, str.length()-1, 1) << "\n";
    }
	return 0;
}