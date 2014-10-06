#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
vector<pair<int,pair<int,int> > >v;
int test,n,m,x,y;
int parent[10001];
int find(int i){
	if(parent[i]==i)
		return i;
	return parent[i]=find(parent[i]);
}
int main(){
	cin>>test;
	while(test--){
		v.clear();
		int cost=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s>>m;
			for(int j=0;j<m;j++){
				scanf("%d%d",&x,&y);
				v.pb(mp(y,mp(i,x)));
			}
		}
		for(int i=0;i<10001;i++)
			parent[i]=i;
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			int p1=find(v[i].sec.fir);
			int p2=find(v[i].sec.sec);
			if(p1==p2)
				continue;
			else{
				parent[p1]=p2;
				cost+=v[i].fir;
			}
		}
		cout<<cost<<endl;
	}
	return 0;
}