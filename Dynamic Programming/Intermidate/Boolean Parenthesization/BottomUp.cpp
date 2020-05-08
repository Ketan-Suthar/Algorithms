#include <bits/stdc++.h>
using namespace std;

map<string, int> result;

int fun(string str, int i, int j, bool isTrue)
{
    if(i > j)
        return 0;
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));    
    if(i == j)
    {
        
        if(isTrue)
            return (result[temp] = str[i] == 'T');
        else
            return (result[temp] = str[i] == 'F');
    }
    
    if(result.find(temp) != result.end())
        return (result[temp]) % 1003;
    
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
                ans += (rt * lt);
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
    return result[temp] = (ans % 1003);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        result.clear();
        cout << fun(str, 0, str.length()-1, 1) << "\n";
    }
    return 0;
}