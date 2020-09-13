class Solution {
public:
    void solve(string in, string out, vector<string> &result)
    {
        if(in == "")
        {
            result.push_back(out);
            return;
        }
        string op1 = out;
        string op2 = out;
        if(in[0]>=97 && in[0]<=122)
        {
            op1.push_back(in[0]);
            op2.push_back(in[0]-32);
            in.erase(in.begin());
            solve(in, op1, result);
            solve(in, op2, result);
        }
        else if(in[0]>=65 && in[0]<=90)
        {
            op1.push_back(in[0]);
            op2.push_back(in[0]+32);
            in.erase(in.begin());
            solve(in, op1, result);
            solve(in, op2, result);
        }
        else
        {
            op1.push_back(in[0]);
            in.erase(in.begin());
            solve(in, op1, result);
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        vector<string> result;
        solve(S,"", result);
        return result;
    }
};