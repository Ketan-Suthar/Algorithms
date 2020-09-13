class Solution {
public:
    bool helper(string s1, string s2)
    {
        if(s1 == s2)
            return true;
        if(s1.size() <= 1)
            return false;
        for(int i = 1; i<s1.size(); i++)
        {
            if(helper(s1.substr(0, i), s2.substr(0, i))
                && helper(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i)))
                return true;
            if(helper(s1.substr(0, i), s2.substr(s2.size()-i, i))
                && helper(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i)))
                return true;
        }
        return false;
    }
    bool isScramble(string s1, string s2)
    {
        if(s1.size() != s2.size())
            return false;
        if(s1.size() == 0 && s2.size() == 0)
            return true;
        return helper(s1, s2);
    }
};