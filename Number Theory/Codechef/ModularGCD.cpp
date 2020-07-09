#include <bits/stdc++.h>

#define REP(i,n) for (int i = 0; i <=n; ++i)
#define mod 1000000007
#define lli long long int
#define ll long long
#define vi std::vector<int>;
#define endl "\n"
using namespace std;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

lli power(lli A, lli n, lli d)
{
	lli res = 1;
	while(n)
	{
		if(n%2)
		{
		    res = ((res%d) * (A%d)) % d;
		    n--;
		}
		else
		{
		    A = ((A%d) * (A%d)) % d;
		    n/=2;
		}
	}
	return res;
}
 
lli GCD(lli A, lli B, lli n)
{
    if(A==B)
        return (power(A,n,mod) + power(B,n,mod)) % mod;
        
    lli candidate = 1;
    lli num = A-B;
    for(lli i=1; i*i<=num; i++)
        if(num%i == 0)
        {
            lli temp = (power(A,n,i) + power(B,n,i)) % i;
            if(temp==0)
            	candidate = max(candidate, i);
           	temp = (power(A,n, num/i) + power(B,n,num/i)) % (num/i);
           	if(temp==0)
            	candidate = max(candidate, num/i);
        }
    return candidate % mod;
}

int main()
{
	FAST;
	// your code goes here
	lli A,B,n,t;
	cin>>t;
	while(t--)
	{
	    cin>>A>>B>>n;
	    
	    cout<<GCD(A,B,n)<<endl;
	}
	return 0;
}
