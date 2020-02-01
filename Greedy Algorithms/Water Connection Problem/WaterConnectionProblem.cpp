#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int houses, pipes;
//i am aasuming maximum number of house is 1000
int outgoing[1000]{0};
int incoming[1000]{0};
int diameter[1000]{0};

vector<int> startHouse; 
vector<int> endHouse; 
vector<int> minDiaOfHouse; 

int minimumDiametr = INT_MAX;

//function to find end of connected component
int DFS(int start)
{
	if(!outgoing[start])
		return start;
	if(diameter[start] < minimumDiametr)
		minimumDiametr = diameter[start];
	return DFS(outgoing[start]);
}

void solveWaterConnectionProblem(int connections[][3])
{
	for(int i=0; i<pipes; ++i)
	{
		int startPoint = connections[i][0],
			endPoint = connections[i][1],
			diame = connections[i][2];

		outgoing[startPoint]=endPoint;
		diameter[startPoint]=diame;
		incoming[endPoint]=startPoint;
	}

	for(int j=1; j<pipes; ++j)
		if(incoming[j]==0 && outgoing[j])
		{
			minimumDiametr = INT_MAX;
			int end = DFS(j);

			startHouse.push_back(j);
			endHouse.push_back(end);
			minDiaOfHouse.push_back(minimumDiametr);
		}

	cout << startHouse.size() << endl; 
    for (int j = 0; j < startHouse.size(); ++j) 
        cout << startHouse[j] << " " << endHouse[j]  << " " << minDiaOfHouse[j] << endl; 
}

int main(int argc, char const *argv[])
{
	cout<<"enter houses and pipes: ";
	cin>>houses>>pipes;
	int connections[pipes][3];

	cout<<"\n enter "<<pipes<<" connections:\n";
	for(int i=0; i<pipes; ++i)
		cin>>connections[i][0]>>connections[i][1]>>connections[i][2];

	solveWaterConnectionProblem(connections);
	return 0;
}