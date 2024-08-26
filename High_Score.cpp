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





void solve(){
 int n;cin>>n;int m;cin>>m;
 vector<vector<int>>edges(n);
 for(int i=0;i<m;i++)
 {
    int a , b , c;cin>>a>>b>>c;
    edges[i] = {a , b , -c};
 }

}

class node{
    public:
    int data;
    node*left;node*right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int ind=0;
node* buildinorder(vector<int>&tree)
{
    int n = tree.size();
    if(ind>=n){
        return NULL;
    }
   if(tree[ind]==-1){
     return NULL;
   }

   node*curr = new node(tree[ind]);
   ind++;
   curr->left = buildinorder(tree);
   ind++;
   curr->right = buildinorder(tree);
   return curr;
}

node* buildpreorder(vector<int>&tree)
{
    int n = tree.size();
    if(ind>=n){
        return NULL;
    }
    if(tree[ind]==-1){
        return NULL;
    }
    node*curr = new node(-1);
    curr->left = buildpreorder(tree);
    curr->data = tree[ind];
    ind++;
    curr->right = buildpreorder(tree);
    return curr;
}
void printpreorder(node * root)
{
    if(root==NULL)return;
    printpreorder(root->left);
    cout<<root->data<<" ";
    printpreorder(root->right);
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
vector<int>order = {1 , 2 , 3};
  node*root =  buildpreorder(order);
  
//   printpreorder(root);
}