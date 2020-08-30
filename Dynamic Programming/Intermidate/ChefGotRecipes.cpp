#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000



int main(int argc, char const *argv[])
{
	int t, freq[32];
	string s;
	int n, mask;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<32; i++) freq[i]=0;

		for (int i = 0; i < n; ++i)
		{
			cin>>s;
			mask=0;
			for(char c: s)
			{
				if(c == 'a') mask |= (1 << 0);
				if(c == 'e') mask |= (1 << 1);
				if(c == 'i') mask |= (1 << 2);
				if(c == 'o') mask |= (1 << 3);
				if(c == 'u') mask |= (1 << 4); 
			}
			freq[mask]++;
		}
		long long int res = 0;
		for (int i = 1; i < 32; ++i)
		{
			for(int j=i+1; j<32; j++)
				if((i|j) == 31)
					res += (freq[i] * freq[j]);
		}
		res = res + (freq[31] * (freq[31] -1))/2;
		cout<<res<<'\n';
	}
	return 0;
}


