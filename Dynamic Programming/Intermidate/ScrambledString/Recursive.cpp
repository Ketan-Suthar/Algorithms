class Solution 
{
public:
    bool fun(string s1, string s2)
    {
        if(s1.compare(s2) == 0)
            return true;
        if(s1.size() <= 1)
            return false;
        int n = s1.size();
        bool flag = false;
        
        for( int i=1; i<n; i++ )
        {
            if
            (
                (
                    (fun(s1.substr(0,i), s2.substr(n-i,i)))
                    && 
                    (fun(s1.substr(i,n-i), s2.substr(0,n-i)))
                ) 
                ||
                (
                    (fun(s1.substr(0,i), s2.substr(0,i))) 
                    && 
                    (fun(s1.substr(i,n-i), s2.substr(i,n-i)))
                )
            )
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
    bool isScramble(string s1, string s2)
    {
        if(s1.size() != s2.size())
            return false;
        if(s1.size() == 0 && s2.size() == 0)
            return true;
        return fun(s1, s2);
    }
};