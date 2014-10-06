#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int test,n,m;
	cin>>test;
	while(test--){
		scanf("%d%d",&n,&m);
		int a[n][m],dp[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				dp[i][j]=0;
			}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i==0)
					dp[i][j]=a[i][j];
				else{
					dp[i][j]=dp[i-1][j];
					if(j>0)
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
					if(j+1<m)
						dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
					dp[i][j]+=a[i][j];
				}

			}

		}
		int ans=0;
		for(int i=0;i<m;i++)
			ans=max(ans,dp[n-1][i]);
		cout<<ans<<endl;
	}
	return 0;
}