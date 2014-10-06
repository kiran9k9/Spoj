#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
using namespace std;
map<int,int>ma;
int n,m,x,y,timer=0;
vector<int>v[5001],trans[5001],conn,final;
vector<pair<int,int> >finish;
int visited[5001],outbound[5001];
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
void dfs1(int i){
	for(int j=0;j<(int)trans[i].size();j++){
		if(!visited[trans[i][j]]){
			visited[trans[i][j]]=1;
			ma[trans[i][j]]=1;
			conn.pb(trans[i][j]);
			dfs1(trans[i][j]);
		}
	}
}
int main(){
	while(1){
		final.clear();
		memset(visited,0,sizeof visited);
		memset(outbound,0,sizeof outbound);
		finish.clear();
		timer=0;
		conn.clear();
		for(int i=0;i<5001;i++){
			v[i].clear();
			trans[i].clear();
		}

		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			v[x].pb(y);
			outbound[x]++;
			trans[y].pb(x);
		}
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				timer++;
				visited[i]=1;
				dfs(i);
			}
		}
		
		sort(finish.rbegin(),finish.rend());
		//for(int i=0;i<finish.size();i++)
		//	cout<<finish[i].fir<<" "<<finish[i].sec<<endl;
		memset(visited,0,sizeof visited);
		int flag=0;
		for(int i=0;i<(int)finish.size();i++){
			flag=0;
			ma.clear();
			if(!visited[finish[i].sec]){
				visited[finish[i].sec]=1;
				ma[finish[i].sec]=1;
				conn.pb(finish[i].sec);
				dfs1(finish[i].sec);
			}
			//cout<<conn.size()<<"fuck"<<endl;
			//cout<<ma[1]<<" "<<conn[1]<<endl;
			if((int)conn.size()>1){
				for(int j=0;j<(int)conn.size();j++){
					for(int k=0;k<(int)v[conn[j]].size();k++){
						//cout<<v[j][k]<<" ARLWE "<<endl;;
						if(ma[v[conn[j]][k]]!=1){
							//cout<<"herfsde";
							conn.clear();
							flag=1;
							break;
						}
					}
					if(flag==1)
						break;
				}
				//cout<<flag<<"dsalkgj "<<endl;
				if(flag==0){
					for(int j=0;j<conn.size();j++)
						final.pb(conn[j]);
				}
			}

			else if(conn.size()==1)
				conn.pop_back();
		//	for(int l=0;l<(int)final.size();l++)
		//		cout<<final[l]<<" ";
			//cout<<"\nHERE";
		}
		//cout<<"HERdE";
		if((int)conn.size()>1){
				for(int j=0;j<conn.size();j++){
					for(int k=0;k<v[conn[j]].size();k++){
						if(ma[v[j][k]]!=1){
							conn.clear();
							flag=1;
							break;
						}
					}
					if(flag==1)
						break;
				}
				if(flag==0){
					for(int j=0;j<conn.size();j++)
						final.pb(conn[j]);
					conn.clear();
				}
			}
			else if(conn.size()==1)
				conn.pop_back();
		
			//cout<<"WTF";
		for(int i=1;i<=n;i++)
			if(outbound[i]==0)
				final.pb(i);
		sort(final.begin(),final.end());
		for(int i=0;i<(int)final.size();i++)
			cout<<final[i]<<" ";
		cout<<endl;
	}
	return 0;
}