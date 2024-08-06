#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
   ll n , m;cin>>n>>m;
   
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
    ll mod = 1e9+7;
    set<int>count[m+1];
    for(int i=0;i<n;i++){
        count[arr[i]].insert(i+1);
    }
 
    int last = -1;
    vector<int>ans(m+1);
    for(int i=m;i>=1;i--)
    {
      auto ele = count[i].upper_bound(last);
      if(ele==count[i].end()){
         ele--;
         ans[i] = *ele; 
      }else{
         ans[i] = *ele;
      }
    }
    vector<pair<ll,ll>>result;
    for(int i=1;i<=m;i++){
        result.push_back({ans[i] , i});
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";cout<<endl;
    sort(result.begin() , result.end());
    ll cnt = 1;
    ll finalans = 0;
    for(auto i: result){
        cout<<i.second<<" ";
    }cout<<endl;
    for(int i=0;i<result.size();i++)
    {
        finalans += (result[i].second*cnt);
        finalans%=mod;
        cnt++;
    }
    cout<<finalans%mod<<endl;
}