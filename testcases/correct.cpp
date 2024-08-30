#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,ans,x,n,sum=0;
	cin>>t;
	while(t--)
	{
		cin>>n>>ans;
		n--;
		while(n--)
		{
			cin>>x;
			if(x)	sum++;
			else ans=ans+(sum/3),sum=0;
			
		}
		cout<<ans+(sum/3)<<"\n";
		sum=0;
	}
}
