//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int atmost(vector<int> &arr, int N, int k)
    {
        int i = 0, j=0;
        vector<int> mp(N+1,0);
        int ans = 0,count=0;
        while(j<arr.size())
        {
            mp[arr[j]]++;
            if(mp[arr[j]]== 1 ){count++;}
            while(count>k)
            {
                mp[arr[i]]--;
                if(mp[arr[i]]==0){count--;}
                i++;
            }
            ans+= j-i+1;
            j++;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        N = *max_element(arr.begin(),arr.end());
        return atmost(arr,N,k) - atmost(arr,N,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends