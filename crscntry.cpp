#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int ans=0;
		vector<int>dp[2001];
		for(int i=0;i<=2000;i++)
			for(int j=0;j<=2002;j++)
				dp[i]
		vector<int>agnes,tom;
		int temp,flag=0;
		while(1){
			scanf("%d",&temp);
			if(temp==0)
				break;
			else{
				agnes.pb(temp);
			}
		}
		while(1){
			tom.clear();
			flag=0;
			while(1){
				scanf("%d",&temp);
				if(temp==0)
					break;
				else{
					flag=1;
					tom.pb(temp);
				}
			}
			if(flag==0)
				break;
			for(int i=0;i<=agnes.size();i++){
				for(int j=0;j<=tom.size();j++){
					if(i==0 or j==0)
						dp[i][j]=0;
					else if(agnes[i-1]==tom[j-1])
						dp[i][j]=dp[i-1][j-1]+1;
					else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
			ans=max(ans,dp[agnes.size()][tom.size()]);
		}
			cout<<ans<<endl;
	}
	return 0;
}