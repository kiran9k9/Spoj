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
	ll n,m;
	scanf("%lld%lld",&n,&m);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	ll ans=0,count=0;
	ll i;
	//cout<<"HERE";
	for(i=1;i<n;i++){
		if(ans>=m)
			break;
		ans+=(ll)(a[i-1]-a[i])*(ll)i;
	}
	i--;
	count=((ll)(ans-m)/i);
	printf("%d\n",count+a[i]);
	return 0;
}