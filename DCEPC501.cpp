#include<iostream>
#include<cstdio>
using namespace std;
long long dp[100010];
int n,a[100010];
long long rec(int pos){
	if(pos>=n)
		return 0;
	long long &ret=dp[pos];
	if(ret!=-1)
		return ret;
	ret=0;
	ret=a[pos]+rec(pos+2);
	if(pos+1<n)
		ret=max(ret,a[pos]+a[pos+1]+rec(pos+4));
	if(pos+2<n)
		ret=max(ret,a[pos]+a[pos+1]+a[pos+2]+rec(pos+6));
	return ret;
}
int main(){
	int test;
	cin>>test;
	while(test--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			dp[i]=-1;
		printf("%lld\n",rec(0));
	} 
	return 0;
}
