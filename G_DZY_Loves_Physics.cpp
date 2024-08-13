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
    vector<pair<long double,long double>>adj[501];
    vector<int>vis2(501 , 0);
    vector<int>vis1(501 , 0);
    
    long double ans = 0.0;
    double dfs(int node ,int parent , long double valnode , long double valedge , vector<long double>&arr){
        
        vis2[node] = 1;
        vis1[node] = 1;
        vector<pair<long double,long double>>values;
        for(auto i:adj[node])
        {
            if(i.first==parent){continue;}
            if(vis2[i.first]==1){
            valedge+=(i.second);
            }else{
            values.push_back(i);
            }
        }
        long double curr =0;
        if(valedge!=0)curr = (valnode/valedge);
        ans = max(ans , curr);
        curr = 0;
        for(auto i:values){
            if(!vis1[i.first])
            dfs(i.first , node , valnode + arr[i.first] , valedge+i.second , arr);
        }
        vis2[node] = 0;
    }
    void yeh_bhi_krr_lete_hain(){
    int n;cin>>n;int m;cin>>m;
    vector<long double>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        int a , b , c;cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b , c});
        adj[b].push_back({a , c});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            vis1[j] = 0;
            
        }
        dfs(i , -1 , arr[i] , 0 , arr);
    }
    cout<<setprecision(18)<<fixed;
    cout<<ans<<endl;
    }
    int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int t=1;
    while(t--){
    yeh_bhi_krr_lete_hain();
    }
    }