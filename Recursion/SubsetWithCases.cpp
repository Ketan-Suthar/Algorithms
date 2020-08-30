#include <bits/stdc++.h>

using namespace std;

void solve(string in, string op)
{
    if(in=="")
    {
        cout<<op<<", "; return;
    }
    string op1 = op;
    string op2 = op;
    
    op1.push_back(in[0]);
    op2.push_back(toupper(in[0]));
    
    in.erase(in.begin());
    
    solve(in, op1);
    solve(in, op2);
}

int main()
{
    string s;
    cin>>s;
    
    for(int i=0;i<s.size();i++)
        s[i] = tolower(s[i]);
    solve(s, "");
    return 0;
}
