#include <iostream>

using namespace std;
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int start[], int end[], int low, int high)  
{  
    int pivot = end[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)  
        if (end[j] < pivot)  
        {  
            i++;
            swap(&start[i], &start[j]); 
            swap(&end[i], &end[j]);  
        }   

    swap(&start[i + 1], &start[high]); 
    swap(&end[i + 1], &end[high]);  
 
    return (i + 1);  
}  

void sortByEndingTime(int start[], int end[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(start, end, low, high);  
  
        sortByEndingTime(start, end, low, pi - 1);  
        sortByEndingTime(start, end, pi + 1, high);  
    }  
}  

void printMaxActivities(int start[], int end[], int n)
{
	int i,j;
	i=0;
	//sort both arrays by their ending time
	sortByEndingTime(start, end, 0, n-1);

	cout<<"\nFollowing activities are selected:\n";
	cout<<"\n"<<start[i]<<" "<<end[i];

	for(j=1;j<n;++j)
	{
		if(start[j]>=end[i])
		{
			cout<<"\n"<<start[j]<<" "<<end[j];
			i = j;
		}
	}

}

int main()
{
	int n;
	cout << "enter number of activities: ";
	cin >>n;
	int start[n],end[n];
	cout<<"\nenter start and end time of "<<n<<" activities:\n";
	for(int i=0;i<n;++i)
		cin>>start[i]>>end[i];

	cout << "\nyou entered:\n";
	for(int i=0;i<n;++i)
		cout<<"("<<start[i]<<","<<end[i]<<"),";

	cout<<"\n";
	printMaxActivities(start, end, n);
}