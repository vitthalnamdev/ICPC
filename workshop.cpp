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
void matrix_multiplication(){
     int n;cin>>n;
     int mat[n][n];
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             cin>>mat[i][j];
        }
     } 
     int ans[n][n];
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j] = 0;
        }
     }

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                ans[i][j]+=(mat[i][k]*mat[k][j]);
            }
        }
     }
     
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
     } 
    
}


// int a , b , c.....d;



void array1(){
    // int arr[2];
    // // arr[i];
    // // arr[2];
    // // 0 , 1 // arr[0] , arr[1].
    // for(int i=0;i<2;i++){
    //     cin>>arr[i];
    // }
    // // outputing the array.
    // for(int i=0;i<2;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    // arr
    // 1111-> 4 bytes.
    // 1111 + 4 =1115
    // ......
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}


void summation(){
    
     int n; 
     cin>>n;
     long long int arr[n];
     long long int  ans = 0;
     for(int i=0;i<n;i++)cin>>arr[i];
     for(int i=0;i<n;i++){
       ans+=arr[i];
     }
     if(ans<0){
        cout<<(ans*-1)<<endl;
     }else{
        cout<<ans<<endl;
     }
}

void searching(){
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)cin>>arr[i];
    int x;cin>>x;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
           cout<<i<<endl;return;
        }
    }
    cout<<-1<<endl;
}


void prefix(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int prefix[n];
    //
    for(int i=0;i<n;i++){
       if(i-1<0){
          prefix[i] = arr[i];
       }else{
          prefix[i] = prefix[i-1] + arr[i];
       }
    }
    int q;cin>>q;

    for(int i=0;i<q;i++){
        int l , r;cin>>l>>r;
        if(l==0){
            cout<<prefix[r]<<endl;
        }else{
            cout<<prefix[r]-prefix[l-1]<<endl;
        }
    }

}


void multidimensional(){
      
}







void solve(){
     prefix();
     
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}