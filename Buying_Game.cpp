#include <bits/stdc++.h>
using ll=long long;
using namespace std;
using vl=vector<ll>;
using st=string;
#define fo(i,n)   for(ll i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define X first
#define Y second
void solve() {
 ll n;cin>>n;ll cnt=0;ll ind=-1;
 vl v(n),v2(n);
 fo(i,n){cin>>v[i];}
 fo(i,n){cin>>v2[i];}
 fo(i,n){
    if(v[i]<v2[i]){ind=i;  
     cnt++;
    }
 }
if(cnt!=1){ll ans=0;fo(i,n){ans+=min(v[i],v2[i]);}cout<<ans<<endl;return;}
else {
ll sum = 0;
 
for(int i=0;i<n;i++){
   sum+=v2[i];
}
ll ans = sum;
fo(i,n){
    if(i==ind){continue;}
    ans = min(ans , sum + v[i] + v[ind] - v2[ind] - v2[i]);
}
 cout<<ans<<endl;
}

}
int main() {ll  t;cin >> t;while (t--) { solve();}return 0;}