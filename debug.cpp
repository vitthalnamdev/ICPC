#include<bits/stdc++.h>
using namespace std;
//--------- DEBUG START---------//
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
//------DEBUG END---------//
 
int main(){
   int a = 10;
   debug(a);
   vector<vector<int>>arr = {{1 , 2 , 3} , { 2, 3, 4}};
   debug (arr);
   set<pair<int,int>>s;
   s.insert({1, 1}); s.insert({2,2});
   debug(s);
}