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
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int main(){
	int test,n,m;
	cin>>test;
	while(test--){
		int flag3=0,flag1=0,flag2=0;
		cin>>n>>m;
		int pos1x,pos1y,pos2x,pos2y,pos3x,pos3y;
		string s[203];
		for(int i=0;i<203;i++)
			for(int j=0;j<203;j++)
				s[i]+='.';
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("\n");
				char ch=getchar();
				s[i][j]=ch;
			}

			
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				//cout<<i<<" i "<<j<<endl;
				if(s[i][j]=='1'){
					flag1=1;
					pos1x=i,pos1y=j;
				}
				if(s[i][j]=='2'){
					flag2=1;
					pos2x=i,pos2y=j;
				}
				if(s[i][j]=='3'){
					flag3=1;
					pos3x=i,pos3y=j;
				}
			}

		/*for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++)
				cout<<s[i][j];
			cout<<endl;
		}*/
		//cout<<pos1x<<" "<<pos1y<<" "<<pos2x<<" "<<pos2y<<" "<<pos3x<<" "<<pos3y<<endl;
		
		if(flag1!=1 and flag2!=1 and flag3!=1){
			printf("0\n");
			continue;
		}

		queue<int>q;
		//cout<<"HERE";
		q.push(pos1x);
		q.push(pos1y);
		
		int visited[203][203],visited1[203][203],visited2[203][203];
		int level[203][203],level2[203][203],level3[203][203];
		memset(visited,0,sizeof visited);
		memset(visited1,0,sizeof visited1);
		memset(visited2,0,sizeof visited2);
		memset(level,0,sizeof level);
		memset(level2,0,sizeof level2);
		memset(level3,0,sizeof level3);
		
		visited[pos1x][pos1y]=1;
		level[pos1x][pos1y]=0;
		
		while(!q.empty()){
			int x=q.front();
			q.pop();
			int y=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				if(!visited[x+dx[i]][y+dy[i]] and x+dx[i]>=0 and x+dx[i]<=n+1 and y+dy[i]>=0 and y+dy[i]<=m+1 and s[x+dx[i]][y+dy[i]]!='#'){
					visited[x+dx[i]][y+dy[i]]=1;
					level[x+dx[i]][y+dy[i]]=level[x][y]+1;
					q.push(x+dx[i]);
					q.push(y+dy[i]);
				}
			}
		}
		q.push(pos2x);
		q.push(pos2y);
		visited1[pos2x][pos2y]=1;
		level2[pos2x][pos2y]=0;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			int y=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				if(!visited1[x+dx[i]][y+dy[i]] and x+dx[i]>=0 and x+dx[i]<=n+1 and y+dy[i]>=0 and y+dy[i]<=m+1 and s[x+dx[i]][y+dy[i]]!='#'){
					visited1[x+dx[i]][y+dy[i]]=1;
					level2[x+dx[i]][y+dy[i]]=level2[x][y]+1;
					q.push(x+dx[i]);
					q.push(y+dy[i]);
				}
			}
		}
		q.push(pos3x);
		q.push(pos3y);
		visited2[pos3x][pos3y]=1;
		level3[pos3x][pos3y]=0;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			int y=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				if(!visited2[x+dx[i]][y+dy[i]] and x+dx[i]>=0 and x+dx[i]<=n+1 and y+dy[i]>=0 and y+dy[i]<=m+1 and s[x+dx[i]][y+dy[i]]!='#'){
					visited2[x+dx[i]][y+dy[i]]=1;
					level3[x+dx[i]][y+dy[i]]=level3[x][y]+1;
					q.push(x+dx[i]);
					q.push(y+dy[i]);
				}
			}
		}
		int ans=1000000000;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++){
				if(visited[i][j] and visited1[i][j] and visited2[i][j])
					ans=min(ans,max(level[i][j],max(level2[i][j],level3[i][j])));
			}
		cout<<ans<<endl;
	}
	return 0;
}