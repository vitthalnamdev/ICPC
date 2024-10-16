#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

////--------- DEBUG START---------////
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
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

// flags to use: g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

class Dsu {
public:
    vector<int> rank, parent;

    Dsu(int x) {
        rank.resize(x + 1, 0);
        parent.resize(x + 1);
        for (int i = 0; i <= x; i++) parent[i] = i;
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]); // Path compression
        }
        return parent[a];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    bool draw_edge(int a, int b, vector<int>& ans, int time) {
        int parenta = find(a);
        int parentb = find(b);

        if (parenta == parentb) {
            return false;
        }
        // if(a==3 && b==1){
        //   cout<<parenta<<" "<<parentb<<endl;
        //   cout<<rank[parenta]<<" "<<rank[parentb]<<endl;
        // }
        if (rank[parenta] > rank[parentb]) {
             
            parent[parentb] = parenta;
            if(parenta==1)
            ans[parentb] = time;
        } else if (rank[parentb] > rank[parenta]) {
            parent[parenta] = parentb;
        
            rank[parentb]++;
            if(parentb==1)
            ans[parenta] = time;
        } else {
            parent[parentb] = parenta;
            rank[parenta]++;
            if(parenta==1)
            ans[parentb] = time;
        }

        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    map<pair<int, int>, int> ismapped;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == -1) {
            s.insert({i, 2});
            ismapped[{i, 2}] = b;
        } else if (b == -1) {
            s.insert({i, 1});
            ismapped[{i, 1}] = a;
        } else {
            s.insert({i, 1});
            s.insert({i, 2});
            ismapped[{i, 1}] = a;
            ismapped[{i, 2}] = b;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
