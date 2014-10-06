#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
int n;
vector<pair<int,int> >v[50005];
int visited[50005],maxi=0,main_value=0,dist[50005];
void dfs(int index){
	for(int i=0;i<v[index].size();i++){
		if(!visited[v[index][i].fir]){
			visited[v[index][i].fir]=1;
			dist[v[index][i].fir]=dist[index]+v[index][i].sec;
			if(dist[v[index][i].fir]>maxi){
				maxi=dist[v[index][i].fir];
				main_value=v[index][i].fir;
			}
			dfs(v[index][i].fir);
		}
	}
	return;
}
int main(){
	int test,x,y,z;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		memset(dist,0,sizeof dist);
		memset(visited,0,sizeof visited);	
		int start;
		for(int i=0;i<50005;i++)
			v[i].clear();
		for(int i=0;i<n-1;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(i==0)
				start=x;
			v[x].pb(mp(y,z));
			v[y].pb(mp(x,z));
		}
		main_value=0;
		visited[start]=1;
		dist[start]=0;
		maxi=-1;
		dfs(start);
		//cout<<main_value<<endl;
		memset(visited,0,sizeof visited);
		memset(dist,0,sizeof dist);
		visited[main_value]=1;
		dist[main_value]=0;
		maxi=-1;
		dfs(main_value);
		printf("%d\n",maxi);
	}
	return 0;
}