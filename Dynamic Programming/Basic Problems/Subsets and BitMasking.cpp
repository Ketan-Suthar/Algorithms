#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000


int main(int argc, char const *argv[])
{
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int tot = 1<<n;
		for(int mask = 0; mask<tot; mask++)
		{
			int i=0, temp=mask;
			while(temp>0)
			{
				(temp&1) ? cout<<arr[i] : cout<<"";
				i++;
				temp = temp>>1;
			}
			cout<<'\n';
		}
	}

	return 0;
}

