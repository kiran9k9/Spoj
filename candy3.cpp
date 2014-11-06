#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("\n");
		int n;
		scanf("%d",&n);
		ll a[n];
		ll ans=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			ans=(ans+a[i])%n;
		}
		if(ans)
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}