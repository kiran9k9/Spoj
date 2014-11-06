#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
#define Max 100010
using namespace std;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ll n;
		scanf("%lld",&n);
		for(ll i=n/2;i>=1;i--){
			if(__gcd(i,n)==1){
				printf("%lld\n",i);
				break;
			}
		}

	}
	return 0;
}