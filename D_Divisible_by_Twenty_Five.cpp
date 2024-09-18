#include<cstdio>
#include<cstring>
int cnt,n;
char s[10];
void dfs(int x,int y,int z){
if(x==n+1){
if(y%25==0)cnt++;
return;
}
if(x>1&&y==0)return;
if(s[x]=='X')if(z!=-1)dfs(x+1,y*10+z,z);
else for(int i=0;i<=9;i++)dfs(x+1,y*10+i,i);else if(s[x]!='_')dfs(x+1,y*10+s[x]-48,z);
else for(int i=0;i<=9;i++)dfs(x+1,y*10+i,z);
}
int main(){
scanf("%s",s+1);n=strlen(s+1);
dfs(1,0,-1);
printf("%d\n",cnt);
}
// #include<iostream>
// using namespace std;
// string s;
// main()
// {
// 	int ans=0;
// 	cin>>s;
// 	for(int k=0;;k+=25)
// 	{
// 		string t=to_string(k);
// 		if(s.size()<t.size())break;
// 		if(s.size()>t.size())continue;
// 		char x='-';
// 		bool ok=true;
// 		for(int i=0;i<s.size();i++)
// 		{
// 			if(s[i]=='_');
// 			else if(s[i]=='X')
// 			{
// 				if(x=='-')x=t[i];
// 				else if(x!=t[i])
// 				{
// 					ok=false;
// 					break;
// 				}
// 			}
// 			else if(s[i]!=t[i])
// 			{
// 				ok=false;
// 				break;
// 			}
// 		}
// 		if(ok)ans++;
// 	}
// 	cout<<ans<<endl;
// }
