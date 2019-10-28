//median of two sorted array of different length
#include <iostream>
#include <cmath>
using namespace std;

float findMedian(int x[],int y[],int m,int n)
{
	if(m>n) //to ensure that m<=n
		findMedian(int y[],int x[],n,m)

	int start=0,end=m,halflen = (m+n+1)/2;

	while(start<= end)
	{
		int partX = (start+end)/2;
		int partY = halflen - partX;

		if(i < end && y[partY-1] > x[partX-1])
			start = partX + 1; // start is to small
		else if(i > start && x[partX-1] > y[partY])
			end = partX - 1;
		else
		{
			int maxleft =0;
			if(i==0)
				maxleft = y[partY-1];
			else if(j==0)
				maxleft = x[partX-1];
			else
				maxleft = max(y[partY-1], x[partX-1])

			int minright=0;
			if(i==m)
				minright = y[partY-1];
			else if(j==n)
				minright = x[partX-1];
			else
				minright = min(y[partY-1], x[partX-1])

			return (minright+maxleft) / 2.0;
		}

	}
	return 0.0;
}

int main(int argc, char const *argv[])
{
	int m,n;
	int *x,*y;
	cour<<"\nenter length of array1: ";
	cin>>m;

	x= new int[m];
	cout<<"\n enter "<<m<<" values: ";
	for(int i=0;i<m;++i)
		cin>>x[i];

	cour<<"\nenter length of array2: ";
	cin>>n;
	y= new int[n];
	cout<<"\n enter "<<y<<" values: ";
	for(int i=0;i<y;++i)
		cin>>y[i];

	float median = findMedian(x,y,m,n);
	cout<<"median of given two sorted array: "<<median;
	return 0;
}