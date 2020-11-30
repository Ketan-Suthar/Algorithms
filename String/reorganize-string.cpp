// https://www.leetcode.com/problems/reorganize-string/submissions/

class Solution {
public:
    struct Key
    {
        int freq;
        char c;
        bool operator<(const Key& k) const
        {
            return freq < k.freq;
        }
    };
    string reorganizeString(string str)
    {
        int freq[26]{0};
        for(char c: str)
            freq[c - 'a'] += 1;
        
        priority_queue<Key> pq;
        for(char c='a'; c <= 'z'; c++)
            if(freq[c - 'a'])
                pq.push(Key{ freq[c - 'a'], c });
        string result;
        Key prev{-1, '#'};
        
        while(!pq.empty())
        {
            Key key = pq.top();
            cout<<key.c<<" "<<key.freq<<"\n";
            pq.pop();
            result.push_back(key.c);
            
            if(prev.freq > 0)
                pq.push(prev);
            
            (key.freq)--;
            prev = key;
        }
        if(prev.freq > 0)
        {
            if(prev.freq > 1 || (result[result.size()-1] == prev.c))
                return "";
            result.push_back(prev.c);
        }
        return result;
    }
};