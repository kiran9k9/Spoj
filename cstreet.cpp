#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <queue>
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define mp make_pair
#include <queue>
using namespace std;
vector<pair<int,pair<int,int> > >v;
int parent[1001];
int find(int i){
	if(parent[i]==i)
		return parent[i];
	return parent[i]=find(parent[i]);
}
int test,n,p,m,a,b,c;
int main(){
	scanf("%d",&test);
	while(test--){
		v.clear();
		int ans=0;
		scanf("%d%d%d",&p,&n,&m);
		for(int i=1;i<=n;i++)
			parent[i]=i;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			v.pb(mp(c,mp(a,b)));
			v.pb(mp(c,mp(b,a)));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			int p1=find(v[i].sec.fir);
			int p2=find(v[i].sec.sec);
			if(p1==p2)
				continue;
			else{
				parent[p1]=p2;
				ans+=v[i].fir*p;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}