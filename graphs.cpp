#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<pair<int,int>>adj[100010];
// minimum distance.
vector<ll>dist(100010,LLONG_MAX);
// count of minimum distance.
vector<ll>dp(100010,0);
// make a visited array.
vector<int>vis(100010 , 0);
// another arrays for counting the nodes between 1 and n . 
vector<int>singlemx(100010 , 0);
vector<int>singlemn(100010 , INT_MAX);
int mod = 1e9+7;
// Dijectra algorithm.

void path(){
   set<pair<ll,int>>s;
   dist[1] = 0;
   s.insert({0,1});
   dp[1] = 1;
   singlemn[1] = 0;
   while(!s.empty()){
     
      auto top = *s.begin();
      s.erase(s.begin());
     
     if(vis[top.second])continue;
     vis[top.second] = 1;
      
     for(auto i: adj[top.second]){
          
          if(dist[i.first] > top.first + i.second){
               dist[i.first] = top.first + i.second;
               dp[i.first] = 0;
               singlemx[i.first] = 0;
               singlemn[i.first] = INT_MAX;
               s.insert({dist[i.first] , i.first});
           }
          if(dist[i.first] == top.first + i.second){
             dp[i.first] += (dp[top.second]);
             dp[i.first]%=mod;
             singlemx[i.first] = max(singlemx[i.first] , singlemx[top.second] + 1);
             singlemn[i.first] = min(singlemn[i.first] , singlemn[top.second] + 1);
          }
     }

   }
}


int main(){
 int n , m;cin>>n>>m;
 
 for(int i=1;i<=m;i++){
     int a , b , c;cin>>a>>b>>c;
     adj[a].push_back({b,c});
 }
 
 path();
 cout<<dist[n]<<" "<<dp[n]<<" "<<singlemn[n]<<" "<<singlemx[n]<<endl;

}