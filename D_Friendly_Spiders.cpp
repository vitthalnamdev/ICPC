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



const int N = 3e5+10;
vector<int>prime(N,0);
void sieve(){
 for(int i=0;i<N;i++){
    prime[i] = i;
 }
 for(int i=2;i*i<N;i++)
 {
    for(int j=i*i;j<N;j+=i)
    {
        if(prime[j]==j){
            prime[j] = i;
        }
    }
 }
 
}

vector<int>adj[300010];
vector<int>dist(300010,INT_MAX);
vector<int>parent(300010 , -1);

void bfs(int node,vector<int>&arr)
{
    dist[node] = 0;
    queue<int>q;
    int n = arr.size();
 
    q.push(node);
     
    while(!q.empty())
    {
        int top = q.front();
        
        q.pop();
        vector<int>factors;
        int num = arr[top];
        while(num>1){
            int factor = prime[num];
            factors.push_back(factor);
            while(num%factor==0)num/=factor; 
        }
        for(auto i:factors){
            for(auto j:adj[i])
            {
                if( dist[j]>dist[top]+1){
                    dist[j] = dist[top]+1;
                    parent[j] = top;
                     
                    q.push(j);
                }
                adj[i].clear();   
            }
        }
    }
}
vector<int> path(int ind){
  vector<int>result;
  while(ind!=-1){
    result.push_back(ind);
    ind = parent[ind];
  }
  reverse(result.begin() , result.end());
  return result;
}
void solve(){
  int n;cin>>n;
  vector<int>legs(n);
  for(int i=0;i<n;i++)cin>>legs[i];
  int sender,reciever;cin>>sender>>reciever;
  sender--;reciever--;
 
 
  for(int i=0;i<n;i++){
      int num = legs[i];
      while(num>1){
         int factor = prime[num];
         adj[factor].push_back(i);
         while(num%factor==0)num/=factor;
      }
  }
  bfs(sender , legs);
 vector<int>ans =  path(reciever);
  if(ans[0]==sender && ans.back()==reciever){
     cout<<ans.size()<<endl;
     for(auto i:ans){
        cout<<i+1<<" ";
     }cout<<endl;
  }else{
    cout<<-1<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
sieve();
solve();
}