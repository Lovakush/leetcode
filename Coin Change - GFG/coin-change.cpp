//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long>> dp(N,vector<long>(sum+1,0));
        for(int s=0;s<=sum;s++)
            dp[0][s] = (s%coins[0]==0);
        for(int ind=1;ind<N;ind++)
        {
            for(int s=0;s<=sum;s++)
            {
                long int notTake = dp[ind-1][s];
                long int Take = 0;
                if(coins[ind]<=s)
                    Take = dp[ind][s-coins[ind]];
                dp[ind][s] = notTake + Take; 
            }
        }
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends