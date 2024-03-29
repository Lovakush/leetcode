//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.length();
	    int m = str2.length();
	    vector<int> prev(m+1,0),curr(m+1,0);
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(str1[i-1]==str2[j-1])curr[j] = 1 + prev[j-1];
	            else 
	                curr[j] = max(curr[j-1],prev[j]);
	        }
	        prev = curr;
	    }
	    int lcs = prev[m];
	    int insert = m - lcs;
	    int dele = n-lcs;
	    return insert + dele;
	    
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends