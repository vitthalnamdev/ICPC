#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
////--------- DEBUG START---------////
#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(long long int a ){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr << a;}
template<class T1 , class T2>void _print(pair<T1,T2>a){cerr<<"{ ";cerr<<a.first<<" "<<a.second;cerr<<" }";}
template<class T>void _print(vector<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(set<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(multiset<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
////------DEBUG END---------////
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
bool dfs(int node  , vector<int>adj[] , vector<int>&arr , int ele , int mn ){
     
  int mn = mn-arr[node]; 
  for(auto i:adj[node]){    
   bool  now = dfs(i , adj , arr , ele ,  mn );
    
  }
 return arr[node];
}
 
void solve(){
 int n;cin>>n;
 vector<int>arr(n+1);
 for(int i=1;i<=n;i++)cin>>arr[i];
 vector<int>adj[n+1];
 for(int i=2;i<=n;i++){
    int x;cin>>x;
   adj[x].push_back(i);
 }
  int start = 0 ,end = 1e9;
  int mid;
   cout<<dfs(1 , adj , arr , 6, 6  )<<endl;
//   while(end-start>1)
//   {
//     mid = (start + end)/2;
//     if(check(1 , mid , adj , arr)){
//        start = mid;
//     }else{
//         end = mid - 1;
//     }
//   }
//   if(check(1 , end , adj , arr))
//   {
//     cout<<end<<endl;
//   }else{
//     cout<<start<<endl;
//   }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}