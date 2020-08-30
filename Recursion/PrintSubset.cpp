#include <bits/stdc++.h> 

using namespace std;


void solve(string in, string out)
{
    if(in == "")
    {
        cout<<out<<", ";
        return;
    }
    string op1 = out;
    string op2 = out;
    
    op2.push_back(in[0]);
    
    in.erase(in.begin());
    
    solve(in, op1);
    solve(in, op2);
}

int main()
{
    string s;
    cin>>s;
    
    solve(s, "");
    
    return 0;
}
