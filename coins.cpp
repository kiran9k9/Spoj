#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
map<ll,ll>m;
ll rec(ll n){
	if(n==0 or n==1)
		return 0;
	if(m[n]!=0)
		return m[n];
	return m[n]=max(n,rec(n/2)+rec(n/3)+rec(n/4));
}
int main(){
	ll n;
	while(cin>>n){
		m.clear();
		m[n]=max(n,rec(n/2)+rec(n/3)+rec(n/4));
		cout<<m[n]<<endl;
	}
	return 0;
}