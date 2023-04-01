//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void bfs(int node,vector<int> ad[],vector<int> &vis)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto x: ad[node])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=1;
                } 
                
            }
        }
         
        
    }
    public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V+1,0);
        vector<int> ad[V+1];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    ad[i+1].push_back(j+1);
                    ad[j+1].push_back(i+1);
                }
            }
        }
        int count = 0;
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(i,ad,vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends