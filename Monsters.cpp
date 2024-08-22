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
vector<vector<int>>timer(1001 , vector<int>(1001 , INT_MAX));
vector<vector<int>>monstervisited(1001 , vector<int>(1001 , 0));
bool istrue(int x , int y , vector<string>&arr){
    int n = arr.size();int m = arr[0].size();
    return x>=0 && y>=0 && x<n && y<m && arr[x][y]!='#';
}

void bfsmonsters(vector<string>&arr)
{
    int n = arr.size();int m = arr[0].size();
    queue<pair<int,int>>q;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(arr[i][j]=='M'){
            q.push({i,j});
            timer[i][j] = 0;
           }
        }
     }
     vector<int>dir = {-1 , 1};
     while(!q.empty())
     {
        auto top = q.front();
        q.pop();
        int x = top.first;int y = top.second;
        if(monstervisited[x][y]){
            continue;
        }
        monstervisited[x][y] = 1;
        for(auto i: dir)
        {
           if(istrue(x+i , y , arr) && timer[x][y]!=INT_MAX){
               timer[x+i][y] =min(timer[x+i][y] ,  timer[x][y] + 1);
               q.push({x+i , y});
           }
           if(istrue(x , y+i , arr) && timer[x][y]!=INT_MAX){
              timer[x][y+i] = min(timer[x][y+i] , timer[x][y] + 1);
              q.push({x , y+i});
           }
        }
     }
}
vector<vector<pair<int,int>>>parent(1001 , vector<pair<int,int>>(1001 , {-1,-1}));
 


pair<int,int> bfs(int x , int y , vector<string>&arr  ){
    int n = arr.size();int m = arr[0].size();
    queue<pair<int,int>>q;
    q.push({x,y});
    vector<int>dir = {-1 , 1};
    vector<vector<int>>vis(n+1 , vector<int>(m+1 , 0));
    vector<vector<int>>dist(n , vector<int>(m,INT_MAX));
    dist[x][y] = 0;
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        int i = top.first;int j = top.second;
        for(auto k:dir){ 
            if(istrue (i+k , j , arr) && timer[i+k][j]>dist[i][j]+1 && !vis[i+k][j]){
                parent[i+k][j] = {i,j};
                q.push({i+k ,j});
                dist[i+k][j] = dist[i][j]+1;
            }
            if(istrue (i , j+k , arr) && timer[i][j+k]>dist[i][j]+1 && !vis[i][j+k]){
                parent[i][j+k] = {i,j};
                q.push({i,j+k});
                dist[i][j+k] = dist[i][j]+1;
            }
        }
    }
    int ans = INT_MAX;
    pair<int,int>end={-1,-1};
    for(int i=0;i<n;i++){
       if(arr[i][0]<ans){
        ans = arr[i][0];
        end = {i,0};
       }
       if(arr[i][m-1]<ans){
         ans= arr[i][m-1];
         end = {i,m-1};
       }
    }
    for(int i=0;i<m;i++){
        if(arr[0][i]<ans){
            ans = arr[0][i];
            end = {0,i};
        }
        if(arr[n-1][i]<ans){
            ans = arr[n-1][i];
            end = {n-1,i};
        }
    }
    return end;
}

void getpath(pair<int,int>&start , pair<int,int>&end){
     string ans = "";
  
     while(start!=end){
        pair<int,int> par = parent[end.first][end.second];
        if(par.first-end.first==1){
            ans+='U';
        }else if(par.first-end.first==-1){
           ans+='D';
        }
        if(par.second-end.second==1){
            ans+='L';
        }else if(par.second-end.second==-1){
            ans+='R';
        }
        end = par;
     }
     reverse(ans.begin(),ans.end());
     cout<<ans.size()<<endl;
     cout<<ans<<endl;
}

#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
void solve(){
 int n , m;cin>>n>>m;
 vector<string>arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
  bfsmonsters(arr);
  pair<int,int>start={-1,-1};
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]=='A'){
            start = {i,j};break;
        }
    }
    if(start!=make_pair(-1,-1)){
        break;
    }
  }
  auto end = bfs(start.first , start.second , arr);
  if(end==make_pair(-1,-1)){
        cout<<"NO"<<endl;
  }else{
       cout<<"YES"<<endl;
        getpath(start , end);
  }

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}