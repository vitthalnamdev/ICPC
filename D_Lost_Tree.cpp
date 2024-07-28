#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
 int n;cin>>n;
 vector<int>level(n+1);
 vector<pair<int,int>>ans;
 cout<<"? "<<1<<endl;
  
 for(int i=1;i<=n;i++)cin>>level[i];
 int odd = 0, even = 0;
 vector<int>evennodes , oddnodes;
 for(int i=1;i<=n;i++){
    if(level[i]%2) oddnodes.push_back(i);
    else evennodes.push_back(i);
 }
 
 if(evennodes.size()>oddnodes.size()){
     
    for(int i=0;i<oddnodes.size();i++){
        if(oddnodes[i]==1){
            for(int j=1;j<=n;j++){
            if(level[j]==1){
                ans.push_back({oddnodes[i] , j});
            }
         }
        }else{
            cout<<"? "<<oddnodes[i]<<endl;
            
            for(int j=1;j<=n;j++){
                int x;cin>>x;
                if(x==1){
                    ans.push_back({oddnodes[i] , j});
                }
            }
        }
    }
 }else{
    for(int i=0;i<evennodes.size();i++){
        if(evennodes[i]==1){
         for(int j=1;j<=n;j++){
            if(level[j]==1){
                ans.push_back({evennodes[i] , j});
            }
         }
        }else{
         cout<<"? "<<evennodes[i]<<endl;
         
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            if(x==1){
                ans.push_back({evennodes[i] , j});
            }
        }
        }
    }
 }
 cout<<"!"<<endl;
 for(auto i: ans){
    cout<<i.first<<" "<<i.second<<endl;
 }cout<<flush;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}