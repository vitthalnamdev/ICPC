#include<bits/stdc++.h>
using namespace std;
string s;
int fail[400000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,i,j;
	cin>>s;
	n=s.length();
	fail[0]=0;
	j=0;
	for(i=1;i<n;i++)
	{
		while(j>0&&s[i]!=s[j])j=fail[j-1];
		if(s[i]==s[j])j++;
		fail[i]=j;
	}
	if(fail[n-1]*2>n)
	{
		cout<<"YES\n";
		for(i=0;i<fail[n-1];i++)cout<<s[i];
		cout<<'\n';
	}
	else cout<<"NO\n";
	return 0;
}