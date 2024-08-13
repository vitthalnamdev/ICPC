#include<bits/stdc++.h>
using namespace std;
#define ll long long 
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
int calculate(vector<vector<int>>&arr){
   int ans = 0;
   for(int i=0;i<arr.size();i++){
      int now = 0;
      for(int j=0;j<arr[0].size();j++){
          now^=arr[i][j];
      }
      ans+=now;
   }
   for(int i=0;i<arr[0].size();i++){
      int now = 0;
      for(int j=0;j<arr.size();j++){
        now^=(arr[j][i]);
      }
      ans+=now;
   }
   if(ans==0){
      debug(arr);
   }
}
 

void print(vector<vector<int>>&arr)
{
   int n = arr.size();
   int m = arr[0].size();

   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)cout<<arr[i][j]<<" ";cout<<endl;
   }
}


void recursion(vector<vector<int>>&arr , int i ,int j){
   int n = arr.size();
   int m = arr[0].size();
   if(i>=n){
      return;
   }
   if(j>=m){
      recursion(arr , i+1 , 0);
   }
   arr[i][j] = 1;
   recursion(arr , i+1 , j);
   arr[i][j] = 0;
   recursion(arr , i+1 , j);
}
 
void solve(){
   vector<vector<int>>arr(4 , vector<int>(4 , 0));
   for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
         cout<<arr[i][j]<<" ";
      }cout<<endl;
   }
   
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}