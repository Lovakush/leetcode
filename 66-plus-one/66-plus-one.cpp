class Solution {
public:
    vector<int> plusOne(vector<int> &digit)
{
    int n = digit.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (digit[i] < 9)
        {
            digit[i]++;
            break;
        }
        else if (digit[i] == 9 && i == 0)
        {
            digit[i] = 0;
            digit.insert(digit.begin(), 1);
        }
        else
        {
            digit[i] = 0;
        }
    }
    return digit;
}
};