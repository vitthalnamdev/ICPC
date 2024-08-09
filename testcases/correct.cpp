#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
// int mod = 1e9+7;
// ll inv(ll a) {
// return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
// }
// #define cntone(x) __builtin_popcountll(x)
// #define trailzero(x) __builtin_clzll(x)
// #define trailone(x) __builtin_ctzll(x)
const int N = 200005;
ll tree[4*N + 10];
 ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
 ll build(ll l , ll r , ll ind , vector<ll>&arr)
{    
    if(l==r){return tree[ind] = arr[l];}
  
    ll mid = (l + r) /2 ;
    ll left = build(l , mid , 2*ind , arr );
    ll right = build( mid + 1, r , 2*ind + 1 , arr);
    return tree[ind] = gcd(left , right );
}
 ll find(ll start , ll end , ll l , ll r , ll ind){
    
   if(start>=l && end<=r){return tree[ind];}
   if(start>r || end<l){return 0;}
   
   ll mid = (start+ end )/2;
   ll left = find(start , mid , l , r , 2*ind);
   ll right = find(mid + 1, end , l , r , 2*ind + 1); 
   return __gcd(left , right );
}
  bool query(ll ele , vector<ll>&nums){
    ll n = nums.size();
   for(int i=0;i<n;i++){
     if(i+ele-1>=n){return false;}
    
     ll g = find(0 , n-1 , i , i + ele - 1 , 1);
     if(g>1){ return true;}
   }
   return false;
}
void solve(){
 ll n;cin>>n;

 ll arr[n];
 for(int i=0;i<n;i++)cin>>arr[i];
 if(n==1){
    cout<<1<<endl;return;
 }
 vector<ll>newarr;
 for(int i=0;i<n-1;i++){
    newarr.push_back(abs(arr[i] - arr[i+1]));
 }
  
  build (0 , newarr.size() - 1 , 1 , newarr);
  ll start = 0 , end = n;
     
    
  while(end - start>1 ){
    ll mid = (end + start ) / 2;
    
    if(query(mid , newarr))
    {
        start = mid ;
    }else{
        end = mid - 1;
    }
  }
  
  if(query(end , newarr))
  {
    cout<<end + 1<<endl;
  }else{
    cout<<start +1<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}