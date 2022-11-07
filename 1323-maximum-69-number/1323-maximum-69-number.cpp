class Solution {
public:
    int maximum69Number(int &num)
    {
        string s = to_string(num);
        int n = s.size();
        int x = 0;
        while (n)
        {
            x = (x * 10) + 9;
            n--;
        }
        int diff = x - num;
        cout<<diff<<endl;
        int count = 0;
        while (diff)
        {
            diff = diff / 10;
            count++;
        }
        int add = pow(10, count - 1) * 3;
        return num += add;
    }
};