#include <bits/stdc++.h> 
using namespace std; 

void SelectActivities(vector<int>s,vector<int>f
{ 
// Vector to store results. 
	vector<pair<int,int>>ans; 

// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p; 

	for(int i=0;i<s.size();i++){ 
		// Pushing elements in priority queue where the key is f[i] 
		p.push(make_pair(f[i],s[i])); 
	} 

	auto it = p.top(); 
	int start = it.second; 
	int end = it.first; 
	p.pop(); 
	ans.push_back(make_pair(start,end)); 

	while(!p.empty()){ 
		auto itr = p.top(); 
		p.pop(); 
		if(itr.second >= end){ 
			start = itr.second; 
			end = itr.first; 
			ans.push_back(make_pair(start,end)); 
		} 
	} 
	cout << "\nFollowing Activities should be selected. " << endl << endl; 

	for(auto itr=ans.begin();itr!=ans.end();itr++){ 
		cout << "Activity started at: " << (*itr).first << " and ends at " << (*itr).second << endl; 
	} 
} 

int main() 
{ 
	int n,s,f;
	cout << "enter number of activities: ";
	cin >>n;
	vector<int>start; 
    vector<int>finish;

	cout<<"\nenter start and finish time of "<<n<<" activities:\n";
	for(int i=0;i<n;++i)
	{
		cin>>s>>f;
		start.push_back(s);
		finish.push_back(f);
	}

	cout << "\nyou entered:\n";
	for(int i=0;i<n;++i)
		cout<<"("<<start[i]<<","<<finish[i]<<"),";

	SelectActivities(start,finish); 

	return 0; 
} 
