#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
using namespace std;
vector<int>v[2001];
int test,n,m,x,y,k=0;
int visited[2001],gender[2001],flag=0;
void dfs(int i){
	for(int j=0;j<(int)v[i].size();j++){
		if(!visited[v[i][j]]){
			visited[v[i][j]]=1;
			gender[v[i][j]]=gender[i]^1;
			dfs(v[i][j]);
		}
		if(visited[v[i][j]]){
			if(gender[v[i][j]]^gender[i]==0)
				flag=1;
		}
	}
}
int main(){
	scanf("%d",&test);
	k=test;
	while(test--){
		flag=0;
		memset(visited,0,sizeof visited);
		scanf("%d%d",&n,&m);
		for(int i=0;i<2001;i++){
			v[i].clear();
			gender[i]=-1;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			v[x].pb(y);
			v[y].pb(x);
		}
		for(int i=1;i<=n;i++)
			if(!visited[i]){
				visited[i]=1;
				gender[i]=0;
				dfs(i);
				if(flag==1)
					break;
			}
		cout<<"Scenario #"<<k-test<<":\n";
		if(flag==1)
			cout<<"Suspicious bugs found!\n";
		else cout<<"No suspicious bugs found!\n";
	}
	return 0;
}