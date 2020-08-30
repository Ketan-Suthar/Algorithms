#include <bits/stdc++.h>
using namespace std;

void fun(int arr[], int n)
{
    int _xor=0, setBit=0;
    for(int i=0; i<n; i++)
        _xor = _xor ^ arr[i];
    int temp = _xor;
    
    while(temp>0)
    {
        if(temp&1)
            break;
        ++setBit; temp = temp>>1;
    }
    int mask = (1<<setBit); int firstNum=0;
    for(int i=0; i<n; i++)
        if((mask & arr[i])!=0)
            firstNum ^= arr[i];
    int secondNum = _xor ^ firstNum;
    if(firstNum > secondNum)
        cout<<secondNum <<' '<<firstNum<<'\n';
    else
        cout<<firstNum <<' '<<secondNum<<'\n';
}

int main() {
	//code
	int n,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int size = 2*n+2;
	    int arr[size];
	    for(int i=0; i<size; i++)
	        cin>>arr[i];
	    fun(arr, size);
	}
	return 0;
}