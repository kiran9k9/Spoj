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
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;;i++){
			int val=n/pow(5.0,i);
			if(val==0)
				break;
			else ans+=val;
		}
		cout<<ans<<endl;
	}
	return 0;
}