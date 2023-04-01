//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<vector<int>> bfs(vector<vector<int>> ans,vector<vector<int>> image,
        int row,int col,int newColor,int delrow[],int delcol[])
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        int init = image[row][col];
        ans[row][col] = newColor;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // update 
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==init && ans[nrow][ncol]!=newColor)
                {
                    ans[nrow][ncol] = newColor;
                    q.push({nrow,ncol});
                }
            }
            
        }
        return ans;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        return bfs(ans,image,sr,sc,newColor,delrow,delcol);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends