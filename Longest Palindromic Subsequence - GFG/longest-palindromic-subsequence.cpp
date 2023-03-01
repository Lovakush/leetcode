//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        string B = "";
        int n = A.size();
        for(int i=n-1;i>=0;i--)
            B+=A[i];
        vector<int> prev(n+1,0), curr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends