#include <iostream> 
using namespace std; 

int main(void) 
{ 
	int a,b;
	cout<<"enter two numbers: ";
	cin>>a>>b;
	cout<<"\nnumbers before swap A:"<<a<<" B:"<<b;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout<<"\nnumbers after swap A:"<<a<<" B:"<<b;
	return 0;
}