//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    // vector<int>vis(101, 0);
    // vector<int>Color(101, -1);
    int vis[101];
    int Color[101];
    bool dfs(int node , bool graph[101][101] , int m , int n , int currcolor){
        vis[node] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i]){
                    if(graph[node][i] && j==currcolor){
                        continue;
                    }
                    bool check = dfs(i , graph , m , n , j);
                    if(check==true){
                        return true;
                    }
                }else if(Color[i]==currcolor){
                    return false;
                }
            }
        }
        return true;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        for(int i=0;i<=100;i++){
            Color[i] = -1;
            vis[i] = 0;
        }
        
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bool check = dfs(i , graph , m , n , -1);
                if(check==false){
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends