#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;
using ll =double;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

void solve()
{

    vector<pair<ll,ll>>a;

    ll p;
    cin >> p;
    int n;
    cin >> n;
 ll minp=1e9;
    for (int i = 0; i < n; i++)
    {
        ll x, h;
        cin >> x >> h;

        
        a.push_back({x,x + (h / tan(((double)3.141592653589793238462643383279 * p) / (ll)180))}); 
    }

      ll maxp=0;

  for(auto v:a)
  {
    double x = v.first;double y = v.second;
    maxp=max(x,maxp);
    maxp=max(y,maxp);

    minp=min(x,minp);
    minp=min(y,minp);
  }


    sort(a.begin(),a.end(),[&](const pair<ll,ll>&aa,const pair<ll,ll>&bb)
    { 
        return aa.second<bb.second;
     
    });

     for(int i=0;i<n-1;i++)
     {
         if(a[i].second<a[i+1].first)maxp-=a[i+1].first-a[i].second;
     }

cout<<setprecision(10)<<maxp-minp<<endl;

    
   

  

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}