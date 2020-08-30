#include <bits/stdc++.h>

using namespace std;

void solve(string in, string op)
{
    if(in=="")
    {
        cout<<op<<", "; return;
    }
    string op1 = op;
    
    if(isalpha(in[0]))
    {
        string op2 = op;
        op1.push_back(tolower(in[0]));
        op2.push_back(toupper(in[0]));
        in.erase(in.begin()+0);
        solve(in, op1);
        solve(in, op2);
    }
    else
    {
        op1.push_back(in[0]);
        in.erase(in.begin()+0);
        solve(in, op1);
        return;
    }
    
    
}

int main()
{
    string s, op;
    cin>>s;
    
    solve(s,"");
    return 0;
}
