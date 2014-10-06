#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int n,d,b,c,temp=1;
	while(1){
		cin>>n;
		if(n==0)
			break;
		int a[n][3];
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		int dp[n][3];
		dp[0][1]=a[0][1];
		dp[0][0]=a[0][0];
		dp[0][2]=a[0][2]+a[0][1];
		dp[1][0]=a[1][0]+dp[0][1];
		dp[1][1]=a[1][1]+min(dp[1][0],min(dp[0][2],dp[0][1]));
		dp[1][2]=a[1][2]+min(dp[0][1],min(dp[0][2],dp[1][1]));
		for(int i=2;i<n;i++){
			dp[i][0]=a[i][0]+min(dp[i-1][1],dp[i-1][0]);
			dp[i][1]=a[i][1]+min(dp[i-1][0],min(dp[i-1][1],min(dp[i][0],dp[i-1][2])));
			dp[i][2]=a[i][2]+min(dp[i-1][2],min(dp[i][1],dp[i-1][1]));
		}
		printf("%d. %d\n",temp,dp[n-1][1]);
		temp++;
	}
	return 0;
}