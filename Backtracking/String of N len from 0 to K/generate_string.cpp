#include <iostream>
using namespace std;

char arr[100];

void generateString(int n, int k)
{
	if(n<1)
		cout<<"\n"<<arr;
	else
	{
		for(int j=0;j<k;++j)
		{
			char a = j;
			arr[n-1] = a;
			generateString(n-1,k);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,k;
	cout<<"\nenter size of string: ";
	cin>>n;
	cout<<"\nenter size of K: ";
	cin>>n;
	generateString(n, k);
	return 0;
}