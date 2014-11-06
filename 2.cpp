#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
int m,n;
int power,p2,price[110];
vector<int>v[110];
vector<int>va;
int rec(int i,int mask2){
//	cout<<i<<" "<<mask2<<endl;
	int val=0,count=0;
//	cout<<p2<<endl;
	if(i==n){
		for(int l=0;l<12;l++){
			if( (1<<l) & mask2){
				va.pb(l);
				count++;
			}
		}
		if(count==n){
			return 0;
		}
		else va.clear();
	}
	if(i==n)
		return -1000000000;
	for(int j=0;j<v[i].size();j++){
		if((mask2 &(1<<j))==0){
	//		cout<<v[i][j]-price[j]<<"*"<<endl;
			val=max(val,v[i][j]-price[j]+rec(i+1,(mask2 | (1<<j))));
		}
	}
	return val;
}
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++){
			cin>>price[i];
	}
	
	int temp;
	power=pow(2,n);
	power--;
	p2=pow(2,m);
	p2--;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>temp;
			v[i].pb(temp);
		}
	}
	ll ans1=rec(0,0);
	for(int i=0;i<m;i++){
		int flag=0;
		for(int j=0;j<va.size();j++){
			if(va[j]==i){
				flag=1;
				continue;
			}
		}
		if(flag==0){
			int temp=0;
			for(int j=0;j<m;j++)
				temp=max(temp,v[i][j]-price[j]);
			ans1+=temp;
		}
	}
	cout<<ans1<<endl;
	return 0;
} 