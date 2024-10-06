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
// static void run_with_stack_size(void (*func)(void), size_t stsize) {
//     char *stack, *send;
//     stack = (char *)malloc(stsize);
//     send = stack + stsize - 16;
//     send = (char *)((uintptr_t)send / 16 * 16);
//     asm volatile(
//         "mov %%rsp, (%0)\n"
//         "mov %0, %%rsp\n"
//         :
//         : "r"(send));
//     func();
//     asm volatile("mov (%0), %%rsp\n" : : "r"(send));
//     free(stack);
// }


const int N = 10000010;
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

void solve(){
  int n;cin>>n;
   if(n<=4){
    cout<<0<<endl;
   }
 int ans = 2;
 for(int i=6;i<=n;i++){
     if(prime[i] && prime[i-2]){
        ans++;
     }
 } cout<<ans<<endl;   
}
int main_() {
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
int cnt = 0;
sieve();
while(t--){
cout<<"Case #"<<cnt<<": ";
solve();
cnt++;
}
    // implement your solution here
}
// int main(){
// run_with_stack_size(main_, 1024 * 1024 * 1024);
// }