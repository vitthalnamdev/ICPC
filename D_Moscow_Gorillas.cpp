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
void solve(){
 int n;cin>>n;
 vector<int>p(n+1),q(n+1);
 for(int i=0;i<n;i++){
   int x;cin>>x;p[x] = i;     
 }
 for(int i=0;i<n;i++){
    int x;cin>>x;q[x] = i;
 }
 ll ans = 1;
 ll l =-1;ll r = -1;
 for(int i=1;i<=n;i++){
    if(i==1){
        ll left = min(p[i] , q[i]);
        ll right = max(p[i] , q[i]);
        l = left ; r = right;
        ll middle = right - left -1;
        ans+=((middle*(middle+1))/2);
        ans+=((left*(left+1))/2);
       
        right = n-right-1;
        ans+=((right*(right+1))/2);
          
    }else{
        ll left = min(p[i] , q[i]);
        ll right = max(p[i] , q[i]);
        
        if((left>=l && left<=r) || (right>=l && r>=right)){
         
           
            l = min(l , left );r = max(r , right);continue;
        }
        if(left>r){    
           ll rightr = left - r;
            
           ll leftl =  l+1;
           ans+=(leftl*rightr);
        }else if(right<l){
          
           ll rightr = n-r;
          
        
           ll leftl =  l - right ;
           ans+=(leftl*rightr);
        }else{
           
          ll rightr = right - r;
          ll leftf = left - l;
          ans+=(rightr*leftf);
        }
         
         l = min(l , left );r = max(r , right);
    }
 }
 cout<<ans<<endl;

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t= 1;
while(t--){
solve();
}
}