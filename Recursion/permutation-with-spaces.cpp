#include <bits/stdc++.h>
using namespace std;

void fun(string in, string op)
{
    if(in.length()==0)
    {
        cout<<"("<<op<<")";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(' ');
    op2.push_back(in[0]);
    op1.push_back(in[0]);
    in.erase(in.begin() + 0);
    fun(in, op2);
    fun(in, op1);
}

int main() {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string op;
        op.push_back(s[0]);
        string in = s;
        in.erase(in.begin() + 0);
        fun(in, op);
        cout<<'\n';
    }
	
	return 0;
}