#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

void find_numbers_up_to( int max, unsigned long long int* outs )
{
    unordered_set <unsigned long long int> in_q;
    priority_queue <unsigned long long int, vector<unsigned long long int>, greater<unsigned long long int> > q;
    
    in_q.insert(1);
    q.push(1);
    
    for(int i=0 ; i<max ; i++)
    {
        unsigned long long int val = q.top();
        q.pop();
        in_q.erase(val);
        
        outs[i] = val;
        
        if( in_q.find( val*2 ) == in_q.end() )
            {  q.push(val*2); in_q.insert(val*2);  }
        
        if( in_q.find( val*3 ) == in_q.end() )
            {  q.push(val*3); in_q.insert(val*3);  }
        
        if( in_q.find( val*5 ) == in_q.end() )
            {  q.push(val*5); in_q.insert(val*5);  }
    }
}

int main()
{
    int t;
    cin>>t;
    
    queue <int> inputs;
    int max = 0;
    
    while(t--)
    {
        int temp;
        cin>> temp;
        if(temp>max) max = temp;
        inputs.push(temp);
    }
    
    unsigned long long int* outs = new unsigned long long int[max];
    
    find_numbers_up_to( max, outs );
    
    while( !inputs.empty() )
    {
        cout<< outs[ inputs.front() - 1 ] << endl;
        inputs.pop();
    }
    
	return 0;
}