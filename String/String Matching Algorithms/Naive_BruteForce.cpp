#include <bits/stdc++.h>

using namespace std;

int main()
{
	string T,P;
	int find = -1;
	cin>>T;
	cin>>P;
	int p_size = P.size();
	for(int i=0; i <= T.size() - p_size; i++)
	{
		int j=0;
		for(; j<p_size && T[i+j] == P[j]; j++);
		if(j == p_size)
			cout<<"\nFount At: "<<i<<endl;
	}
	return 0;
}