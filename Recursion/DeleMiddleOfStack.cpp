#include <bits/stdc++.h> 

using namespace std;

void solve(stack<int> &s, int middle)
{
    if(middle == 1)
    {
        s.pop(); return;
    }
    int temp = s.top();
    s.pop();
    solve(s, --middle);
    s.push(temp);
}

void delmiddle(stack<int> &s, int n)
{
    if(n==0)
        return;
    int middle = (n/2) + 1;
    solve(s, middle);
}

int main()
{
    int n, t;
    cin>>n;
    stack<int> s;
    
    for(int i=0;i<n;i++)
        cin>>t, s.push(t);

    delmiddle(s, n);

    while(!s.empty())
        cout<<s.top()<<" ", s.pop();
    return 0;
}
