#include <bits/stdc++.h> 

using namespace std;

void insert(stack<int> &s, int ele)
{
    if(s.size() == 0)
    {
        s.push(ele); return;
    }
    int temp = s.top();
    s.pop();
    insert(s, ele);
    s.push(temp);
}

void reverse(stack<int> &s, int n)
{
    if(n==0 || n==1)
        return;
    int temp = s.top();
    s.pop();
    reverse(s, --n);
    insert(s, temp);
}

int main()
{
    int n, t;
    cin>>n;
    stack<int> s;
    
    for(int i=0;i<n;i++)
        cin>>t, s.push(t);

    reverse(s, n);

    while(!s.empty())
        cout<<s.top()<<" ", s.pop();
    return 0;
}
