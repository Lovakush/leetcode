//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int totsum = 0;
	    for(int i=0;i<n;i++)
	        totsum +=arr[i];
	    vector<bool> prev(totsum+1,0), curr(totsum+1,0);
	    prev[0] = curr[0] = true;
	    prev[arr[0]] = true;
	    for(int i=1;i<n;i++)
	    {
	        for(int target=1;target<=totsum;target++)
	        {
	            int take = prev[target];
	            int notTake = false;
	            if(arr[i]<=target)
	                notTake = prev[target-arr[i]];
	            curr[target] = take or notTake;
	        }
	        prev = curr;
	    }
	    int mini = 1e9;
	    for(int s1= 0;s1<=totsum/2;s1++)
	    {
	        if(prev[s1]==true)
	            mini = min(mini,abs((totsum-s1)-s1));
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends