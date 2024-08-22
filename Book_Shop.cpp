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

  int lcs(string a , string b){
     int n = a.length();int m = b.length();
  
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(a[i-1]==b[j-1]){
               dp[i][j] = max(dp[i][j] , dp[i-1][j-1]+1);
           }           
            dp[i][j] = max(dp[i][j] , max(dp[i-1][j] , dp[i][j-1]));
        }
     }
    return dp[n][m];
  }
   

   class Dsu{
     public:
    int*rank;
    int*parent;
    Dsu(int x){
        rank = new int[x+1];
        parent = new int[x+1];
        for(int i = 0;i<=x;i++)rank[i] = 0;
        for(int i = 0;i<=x;i++)parent[i] = i;
    }
    
    int find(int a){
       if(parent[a]==a)return a;
       return find(parent[a]);
    }

    bool same(int a , int b){
       return find(a)==find(b);
    }
    
    bool Draw_edge(int a, int b){
        int parenta = find(a);
        int parentb = find(b);
    
        if(parenta==parentb){return false;}
        
        if(rank[parenta]>rank[parentb]){
           parent[parentb] = parenta;
        }else if(rank[parentb]> rank[parenta]){
           parent[parenta] = parentb;
        }
        else{
           parent[parentb] = parenta;
           rank[parenta]++;
        }
    
        return true;
    }
    
   };
   

   int longestValidParentheses(string s) {
    stack<int>st;
    st.push(-1);
    int ans=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                cout<<i<<" "<<st.top()<<endl;
                ans=max(ans, i-st.top());
            }
        }
    }
    // 
    return ans;
}
    //()((())()
    // 



 #define cntone(x) __builtin_popcountll(x)
 #define trailzero(x) __builtin_clzll(x)
 #define trailone(x) __builtin_ctzll(x)
 // flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
 void solve(){
    string s;cin>>s;
   longestValidParentheses(s);
 }
 int main(){
 std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
 int t=1;
 while(t--){
 solve();
 }
 }