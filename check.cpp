#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
class DSU{
  public:
  int n;
  int* parent; int *rank;
  DSU(int sz){
     n= sz;
    parent = new int[200005];
    rank = new int[200005];
    for(int i=1;i<=n;i++)parent[i]=i,rank[i] = 0;
  }
  int find(int a){
     if(parent[a]==a){return a;}
     return find(parent[a]);
  }
 
  bool merge(int a, int b){
    
     int parenta = find(a);int parentb = find(b);
     if(parenta == parentb){return false;}
     if(rank[parenta]>rank[parentb]){
        parent[parentb] = parenta;
     }else if(rank[parentb]> rank[parenta]){
        parent[parenta] = parentb;
     }
     else{
        parent[parentb] = parenta;
        rank[parenta]++;
     }
     return true;
  }
 
};
void solve(){
   int n, m;cin>>n>>m;
   DSU now(n+1);
   vector<vector<int>>arr;
   for(int i=0;i<m;i++){
    int a, b, c;cin>>a>>b>>c;
      vector<int>temp = {c, a, b};
      arr.push_back(temp);
   }
   sort(arr.begin(),arr.end());
   ll ans = 0;int count = 0;
  
   for(int i=0;i<m;i++){
    
  
      if(now.merge(arr[i][1],arr[i][2])){
        ans+=(arr[i][0]);count++;
      }
   }
  
   if(count==n-1)
   cout<<ans<<endl;
   else 
   cout<<"IMPOSSIBLE"<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}