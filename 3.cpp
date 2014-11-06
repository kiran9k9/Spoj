#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
ll m,n;
ll power,p2,price[110];
vector<ll>v[110];
ll rec(ll i,ll mask2){
//	cout<<i<<" "<<mask2<<endl;
	ll val=0;
//	cout<<p2<<endl;
	if(i==n and mask2==p2)
		return 0;
	else if(i==n)
		return -1000000000;
	for(ll j=0;j<(1<<m);j++){
		ll temp=0,flag=0;
		for(ll l=0;l<12;l++){
			if(((1<<l) & j)!=0){
				if(((1<<l) & mask2)!=0){
					flag=1;
					break;
				}
				else{
					if(l<m)
						temp+=(v[i][l]-price[l]);
				}
			}
		}
		if(flag==1)
			continue;
		val=max(val,temp+rec(i+1,(mask2 | j)));
		cout<<val<<" here "<<mask2<<endl;
	}
	return val;
}
int main(){
	cin>>m>>n;
	memset(price,0,sizeof price);
	for(ll i=0;i<m;i++){
		cin>>price[i];
	}
	ll temp;
	p2=pow(2,m);
	p2--;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>temp;
			v[i].pb(temp);
		}
	}
	cout<<rec(0,0)<<endl;
	return 0;
}