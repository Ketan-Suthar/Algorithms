#include <iostream>
using namespace std;

char arr[100];

void generateBitString(int n)
{
	if(n<1)
		cout<<"\n"<<arr;
	else
	{
		arr[n-1] = '0';
		generateBitString(n-1);
		arr[n-1] = '1';
		generateBitString(n-1);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"\nenter size of bit: ";
	cin>>n;

	generateBitString(n);
	return 0;
}