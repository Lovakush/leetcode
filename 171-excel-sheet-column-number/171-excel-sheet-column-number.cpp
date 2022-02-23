class Solution {
public:
    int titleToNumber(string columnTitle) {
        string s = columnTitle;
        int result =0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            int d= s[i]-'A'+1;
            result = result*26 +d;
        }
        return result;
    }
};