#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
ll dp[5001][11];
string s;
ll rec(int i ,int digit){
	if(i==s.size()){
		if(digit==10)
			return 1;
		else return 0;
	}
	if(dp[i][digit]!=-1)
		return dp[i][digit];
	dp[i][digit]=0;
	if(digit==0)
		return 0;
	if(digit==10){
		if(s[i]!='0') 
		dp[i][digit]+=rec(i+1,s[i]-'0')+rec(i+1,10);
	}
	if(digit!=10 and digit!=0){
		if(digit*10+(s[i]-'0')<27 and digit*10+(s[i]-'0')>0)
			dp[i][digit]+=rec(i+1,10);
		else return 0;
	}
	return dp[i][digit];
}
int main(){
	
	while(1){
		
		for(int i=0;i<5001;i++)
			for(int j=0;j<11;j++)
				dp[i][j]=-1;

		cin>>s;
		if(s[0]=='0')
			break;
		cout<<rec(0,10)<<endl;
	}
	return 0;

}


