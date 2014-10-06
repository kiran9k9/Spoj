#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
vector<int>v[100001],vt[100001];
vector<pair<int,int> >finish,edges;
int n,m,x,y,deg[100001],visited[100001],value=1,timer=0,compon[100001];
void dfs(int i){
	for(int j=0;j<(int)v[i].size();j++){
		if(!visited[v[i][j]]){
			timer++;
			visited[v[i][j]]=1;
			dfs(v[i][j]);
		}
	}
	timer++;
	finish.pb(mp(timer,i));
}
void dfs2(int i){
	compon[i]=value;
	for(int j=0;j<(int)vt[i].size();j++){
		if(!visited[vt[i][j]]){
			visited[vt[i][j]]=1;
			dfs2(vt[i][j]);
		}
	}
}
		
int main(){
	value=1;
	timer=0;
	memset(compon,0,sizeof compon);
	memset(deg,0,sizeof deg);
	memset(visited,0,sizeof visited);
	edges.clear();
	for(int i=0;i<100001;i++)
		v[i].clear(),vt[i].clear();
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		v[y].pb(x);
		vt[x].pb(y);
		edges.pb(mp(x,y));
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i]=1;
			timer++;
			dfs(i);
		}
	}
	sort(finish.rbegin(),finish.rend());
	memset(visited,0,sizeof visited);
	for(int i=0;i<(int)finish.size();i++){
		if(!visited[finish[i].sec]){
			visited[finish[i].sec]=1;
			dfs2(finish[i].sec);
			value++;
		}
	}
	for(int i=0;i<m;i++){
		if(compon[edges[i].fir]!=compon[edges[i].sec])
			deg[compon[edges[i].fir]]++;
	}
	int count1=0,marker;
	for(int i=1;i<value;i++){
		if(deg[i]==0){
			count1++;
			marker=i;
		}
	}
	//cout<<count1<<endl;
	int count2=0;
	if(count1>1)
		printf("0\n");
	else{
		for(int i=1;i<=n;i++)
			if(compon[i]==marker)
				count2++;
		cout<<count2<<endl;
		for(int i=1;i<=n;i++)
			if(compon[i]==marker)
				cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}