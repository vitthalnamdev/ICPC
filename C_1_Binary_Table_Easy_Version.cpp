#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

//--------- DEBUG START ---------//
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
//------ DEBUG END ---------//

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

// Flags to use
// g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

vector<string> arr;

void four_to_one(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans);
void one_to_two(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans);
void two_to_three(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans);
void three_to_zero(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans);

void four_to_one(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans) {
    vector<int> temp;
    temp.resize(6);
    temp =  {a.first, a.second, b.first, b.second, c.first, c.second};
    ans.push_back(temp);
    one_to_two(d, a, b, c, ans);
}

void one_to_two(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans) {
    vector<int> temp; 
    temp.resize(6);
    temp = {a.first, a.second, b.first, b.second, c.first, c.second};
    ans.push_back(temp);
    two_to_three(b, c, a, d, ans);
}

void two_to_three(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans) {
    vector<int> temp;
    temp.resize(6); 
    temp = {b.first, b.second, c.first, c.second, d.first, d.second};
    ans.push_back(temp);
    three_to_zero(a, c, d, b, ans);
}

void three_to_zero(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d, vector<vector<int>>& ans) {
    vector<int> temp;
    temp.resize(6);
    temp = {a.first, a.second, b.first, b.second, c.first, c.second};
    ans.push_back(temp);
}

void solve() {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> ans;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m;j+=2){
            if(j+1>=m){
                if(arr[i][j]=='0'){continue;}
                ans.emplace_back(i+1 , j+1 , i+2 , j+1 , i+2 , j); 
                arr[i][j]='0';
                if(arr[i+1][j]=='1')
                arr[i+1][j]='0';
                else
                arr[i+1][j]='1';
                if(arr[i+1][j-1]=='1'){
                    arr[i+1][j-1]='0';
                }else{
                    arr[i+1][j-1]='1';
                }
                
                continue;
            }
           if(arr[i][j]=='1' && arr[i][j+1]=='1'){
              
              arr[i][j]='0';arr[i][j+1]='0';
              if(arr[i+1][j]=='1'){
                arr[i+1][j]='0';
                ans.emplace_back(i+1, j+1 , i+1 , j+2 , i+2 , j+1);
              }else{
                if(arr[i+1][j+1]=='1')arr[i+1][j+1]='0';
                else arr[i+1][j+1]='1';
                ans.emplace_back(i+1, j+1 , i+1 , j+2 , i+2 , j+2);
              }
           }else if(arr[i][j]=='1'){
              arr[i][j]='0';
              ans.emplace_back(i+1 , j+1 , i+2 , j+1 , i+2 , j+2);
             
              if(arr[i+1][j]=='0')
              arr[i+1][j]='1';
              else arr[i+1][j] = '0';
              if(arr[i+1][j+1]=='0')
              arr[i+1][j+1]='1';
              else arr[i+1][j+1] = '0';
           }else if(arr[i][j+1]=='1'){
              arr[i][j+1]='0';
              ans.emplace_back(i+1 , j+2 , i+2 , j+1 , i+2 , j+2);
             
              if(arr[i+1][j]=='0')
              arr[i+1][j]='1';
              else arr[i+1][j] = '0';
              if(arr[i+1][j+1]=='0')
              arr[i+1][j+1]='1';
              else arr[i+1][j+1] = '0';
           }
        }
    }
    for(int i=n-2;i<n-1;i++){
    for(int j=0;j<m-1;j++){
      vector<pair<int,int>>ones,zeroes;
      int cnt = 0;
        if(arr[i][j]=='1'){
            cnt++;arr[i][j]='0';
            ones.push_back({i+1 , j+1});
        }else{
            zeroes.push_back({i+1 , j+1});
        }
         if(arr[i+1][j]=='1'){
            arr[i+1][j] = '0';
            cnt++;
            ones.push_back({i+2 , j+1});
         }else{
            zeroes.push_back({i+2 , j+1});
         }
         if(arr[i][j+1]=='1'){
            cnt++;
            arr[i][j+1]='0';
             ones.push_back({i+1 , j+2});
         }else{
            zeroes.push_back({i+1 ,j+2});
         }
         if(arr[i+1][j+1]=='1'){
            arr[i+1][j+1]='0';
            cnt++;
             ones.push_back({i+2 , j+2});
         }else{
             zeroes.push_back({i+2 , j+2});
         }
         if(cnt==1){
            one_to_two(ones[0] , zeroes[0] , zeroes[1] , zeroes[2] , ans);
         }else if(cnt==2){
            two_to_three(ones[0] , ones[1] , zeroes[0] , zeroes[1] , ans);
         }else if(cnt==4){
            four_to_one(ones[0] , ones[1] , ones[2] , ones[3] , ans);
         }else if(cnt==3){
            three_to_zero(ones[0] , ones[1] , ones[2] , zeroes[0] , ans);
         }
         
    }
  }
    cout << ans.size() << endl;
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }cout<<endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}