#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][n],flag=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==m)
				flag=1;
		}
	if(flag==1)
		cout<<"YES\n";
	else cout<<"NO\n";
	
	return 0;
}