#include <iostream>

using namespace std;

void max_water(int arr[], int n)
{
	int max_area = 0,l=0, r=n-1;
	while(l<n)
	{
		max_area = max(max_area,min(arr[l],arr[r])*(r-l));
		if(arr[l]<arr[r])
			++l;
		else
			--r;
	}
	cout<<"\nMaximum water can cantain: "<<max_area;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"\nhow many number you want to enter: ";
	cin>>n;
	int *arr = new int(n);
	cout<<"\nenter "<<n<<" values: ";
	for(int i=0;i<n;++i)
		cin>>arr[i];
	cout<<"\n";
	for(int i=0;i<n;++i)
		cout<<" "<<arr[i];
	max_water(arr,n);

	return 0;
}