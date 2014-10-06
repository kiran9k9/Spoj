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
int endx,endy,t,n,m;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d%d",&n,&m);
		int a[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];

		cin>>endx>>endy>>t;
		endx--;
		endy--;
		queue<int>q;
		q.push(0);
		q.push(0);
		int level[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				level[i][j]=100000000;
		level[0][0]=a[0][0];
		while(!q.empty()){
			int x=q.front();
			q.pop();
			int y=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				if(x+dx[i]>=0 and x+dx[i]<n and y+dy[i]>=0 and y+dy[i]<m and level[x][y]+a[x+dx[i]][y+dy[i]]<level[x+dx[i]][y+dy[i]]){
					level[x+dx[i]][y+dy[i]]=level[x][y]+a[x+dx[i]][y+dy[i]];
					q.push(x+dx[i]);
					q.push(y+dy[i]);

				}
			}
		}
		//cout<<level[endx][endy]<<endl;
		if(level[endx][endy]<=t){
			cout<<"YES\n";
			cout<<t-level[endx][endy]<<endl;
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
