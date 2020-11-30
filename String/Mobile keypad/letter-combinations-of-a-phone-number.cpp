class Solution {
private: string keys[8] = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    void helper(string digits,int i,vector<string> &res)
    {
        static string temp;
        if(i == digits.size())
        {
            res.push_back(temp);
            return;
        }//(stoi(digits[i]))-2
        for(int ind=0;ind<(keys[(digits[i]-'0'-2)].size()); ind++)
        {
            // cout<<keys[(digits[i]-'0'-2)][0]<<' ';//keys[0][0]<<' ';
            temp.push_back(keys[(digits[i]-'0'-2)][ind]);
            helper(digits, i+1, res);
            temp.erase(temp.end()-1);
        }
    }
    public:
        vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(digits.size()==0)
            return res;
        helper(digits, 0, res);
        return res;
    }
};