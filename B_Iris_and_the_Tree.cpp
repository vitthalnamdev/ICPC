#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,w,fa[200005],x,y,a[200005],b[200005],dep[200005],dis[200005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>w;
		for(int i=1;i<=n;i++)dis[i]=a[i]=b[i]=0;
		for(int i=2;i<=n;i++)cin>>fa[i],dep[i]=dep[fa[i]]+1;
		for(int i=1;i<=n;i++){
			int u=i,v=i%n+1;
			while(u!=v){
				if(dep[u]<dep[v])swap(u,v);
				if(!a[u])a[u]=i;
				else b[u]=i;
				dis[i]++,u=fa[u];
			}
		}
		int cnt=n,now=0;
		for(int i=1;i<n;i++){
			cin>>x>>y,dis[a[x]]--,dis[b[x]]--,now+=y;
			if(!dis[a[x]])cnt--;
			if(!dis[b[x]])cnt--;
			cout<<2*now+cnt*(w-now)<<" ";
		}cout<<"\n";
	}
}