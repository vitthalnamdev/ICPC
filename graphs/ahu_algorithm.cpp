// This algorithm works to encode the tree in a way to check two trees are isomorphic or not. 
// Don't look the rank , if you want a good rank
#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
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
long long binpow(long long a, long long b, long long m) {
a %= m;
long long res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
string ahu(vector<int>adj[] , int n ){
  vector<int>indegree(n+1);
  queue<int>q;
  map<int,string>val;
  for(int i=1;i<=n;i++){
    indegree[i] = adj[i].size();
    if(indegree[i]==1){
        q.push(i);
    }
  }
  vector<int>center;
  while(!q.empty())
  {  
     center.clear();
     while(!q.empty()){
        center.push_back(q.front());
        q.pop();
     }
     for(int i=0;i<center.size();i++)
     {
        for(auto j:adj[center[i]])
        {
            val[j]+=val[center[i]];
            indegree[j]--;
            if(indegree[j]==1){
                q.push(j);
                val[j] = '(' + val[j] + ')';
            }
        }
     }
  }
   
  if(center.size()==1){
     return val[center[0]];
  }else{
  
     vector<string>result = {val[center[0]] , val[center[1]]};
     sort(result.begin() , result.end());
     return ('(' +  result[0] + result[1] + ')');
  }
}

void solve(){
   int n;cin>>n;
   vector<int>adj[n+1];
   for(int i=1;i<n;i++){
     int a , b;cin>>a>>b;
     adj[a].push_back(b);
     adj[b].push_back(a);
   }
   string tree1 = ahu(adj , n);
   cout<<tree1<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}