#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int x,y;
		cin>>x>>y;
		if(x==0){
			if(y==0){
				cout<<0<<endl;
				continue;
			}
			else{
				cout<<"No Number\n";
				continue;
			}

		}
		if(x==1){
			if(y==1){
				cout<<1<<endl;
			}
			else cout<<"No Number\n";
			continue;
		}
		if(x%2==0){
			if(y==x){
				cout<<2*y<<endl;
			}
			else if(y==x-2)
				cout<<2*x-2<<endl;
			else cout<<"No Number\n";
		}
		else{
			if(y==x)
				cout<<2*y-1<<endl;
			else if(y==x-2)
				cout<<2*x-3<<endl;
			else cout<<"No Number\n";
		}
	}
	return 0;
}