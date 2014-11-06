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
	int ans=0;
	for(int i=1;i<=n;i++){
		int val=(n/i);
		ans+=min(val,i);
	}
	cout<<ans<<endl;
	return 0;
}