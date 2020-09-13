class Solution {
public:
    void helper(vector<string> &result, string op, int open, int close)
    {
        if(!open && !close)
        {
            result.push_back(op);
            return;
        }
        string op1 = op;
        string op2 = op;
        if(open)
        {
            op1.push_back('(');
            helper(result, op1, open-1, close);
        }
        if(close>open)
        {
            op2.push_back(')');
            helper(result, op2, open, close-1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        int open = n, close = n;
        string out;
        helper(result, out, open, close);
        return result;
    }
};