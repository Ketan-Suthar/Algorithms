#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int freq[32], mask=0;
        memset(freq,0,sizeof(freq));
        while(n--)
        {
            string s;
            cin>>s;
            mask=0;
            for(char ch: s)
            {
                if(ch=='a') mask |= (1<<0);
                if(ch=='e') mask |= (1<<1);
                if(ch=='i') mask |= (1<<2);
                if(ch=='o') mask |= (1<<3);
                if(ch=='u') mask |= (1<<4);
            }
            ++freq[mask];
        }
        long long int res=0;
        for(int i=0; i<32; i++)
        {
            for(int j=i+1;j<32;++j)
            {
                if((i|j)==31)
                    res += (freq[i]*freq[j]);
            }
        }
        res += ((freq[31]*(freq[31]-1))/2);
        cout<<res<<endl;
    }
    return 0;
}
