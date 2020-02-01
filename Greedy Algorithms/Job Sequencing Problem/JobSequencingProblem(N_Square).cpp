#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct job
{
	char id;
	int dead;
	int profit;
};
bool comparison(job a, job b) 
{ 
     return (a.profit > b.profit); 
} 
void maximumProfitJobs(job jobs[], int n)
{
	if(n==0)
		return 0;
	if(n==1)
		cout<<jobs[0].id<<" "<<jobs[0].dead<<" "<<jobs[0].profit<<"\n";

	sort(jobs, jobs+n, comparison);

	bool slots[n]{false};

	for(int i=0;i<n;++i)
	{
		for(int j=min(n,jobs[i].dead)-1; j>=0; --j)
		{
			if(!slots[j])
			{
				cout<<jobs[j].id<<" "<<jobs[j].dead<<" "<<jobs[j].profit<<"\n";
				slots[j] = true;
				break;
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	job jobs[n];
	for(int i=0;i<n;++i)
		cin>>jobs[i].id>>jobs[i].dead>>jobs[i].profit;

	cout<<"\nmaximum profit jobs are:\n";
	maximumProfitJobs(jobs, n);
	return 0;
}