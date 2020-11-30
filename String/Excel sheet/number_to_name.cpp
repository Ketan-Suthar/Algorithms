#define MAX 100
string ExcelColumn(int n)
{
    string res;
    int size = 0;
    while(n > 0)
    {
        int rem = n % 26;
        if(rem == 0)
        {
            res.push_back('Z');
            n = n/26 - 1;
        }
        else
        {
            res.push_back(rem - 1 + 'A');
            n = n/26;
        }
        size++;
    }
    reverse(res.begin(), res.end());
    return res;
} 