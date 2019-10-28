#include <iostream>

using namespace std;

void twosum(int array[],int target,int size)
{
	bool *diff = new bool[target+1];

	for(int i=0;i<=target;++i)
		*(diff+i) = 0;

	int num1=0,num2=0;
	for(int i=0;i<size;++i)
	{
		diff[array[i]] = 1;

		if(diff[target-array[i]] == 1)
		{
			num1 = array[i];
			num2 = target-array[i];
			break;
		}
	}
	cout<<num1<<" + "<<num2<<" = "<<target;
}

int main(int argc, char const *argv[])
{
	
	int *array,n,target;
	char c;
	cout<<"\nEnter size of array: ";
	cin>>n;
	
	array = new int[n];

	for (int i=0;i<n;++i)
		cin>>*(array+i);
	cout<<"\nEnter target(sum): ";
	cin>>target;
	twosum(array,target,n);
	delete array;
	return 0;
}